// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/modules/font_access/font_access.h"

#include <algorithm>

#include "base/feature_list.h"
#include "third_party/blink/public/common/browser_interface_broker_proxy.h"
#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/common/font_access/font_enumeration_table.pb.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/renderer/bindings/core/v8/script_promise_resolver.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_throw_dom_exception.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_query_options.h"
#include "third_party/blink/renderer/core/dom/dom_exception.h"
#include "third_party/blink/renderer/core/execution_context/execution_context_lifecycle_observer.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/modules/font_access/font_metadata.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

using mojom::blink::FontEnumerationStatus;

// static
const char FontAccess::kSupplementName[] = "FontAccess";

FontAccess::FontAccess(LocalDOMWindow* window)
    : ExecutionContextLifecycleObserver(window),
      Supplement<LocalDOMWindow>(*window) {}

void FontAccess::Trace(blink::Visitor* visitor) const {
  ExecutionContextLifecycleObserver::Trace(visitor);
  Supplement<LocalDOMWindow>::Trace(visitor);
}

void FontAccess::ContextDestroyed() {
  remote_.reset();
}

// static
ScriptPromise FontAccess::queryLocalFonts(ScriptState* script_state,
                                          LocalDOMWindow& window,
                                          const QueryOptions* options,
                                          ExceptionState& exception_state) {
  DCHECK(ExecutionContext::From(script_state)->IsContextThread());
  return From(&window)->QueryLocalFontsImpl(script_state, options,
                                            exception_state);
}

// static
FontAccess* FontAccess::From(LocalDOMWindow* window) {
  auto* supplement = Supplement<LocalDOMWindow>::From<FontAccess>(window);
  if (!supplement) {
    supplement = MakeGarbageCollected<FontAccess>(window);
    Supplement<LocalDOMWindow>::ProvideTo(*window, supplement);
  }
  return supplement;
}

ScriptPromise FontAccess::QueryLocalFontsImpl(ScriptState* script_state,
                                              const QueryOptions* options,
                                              ExceptionState& exception_state) {
  if (!base::FeatureList::IsEnabled(blink::features::kFontAccess)) {
    exception_state.ThrowDOMException(DOMExceptionCode::kNotSupportedError,
                                      "Font Access feature is not supported.");
    return ScriptPromise();
  }
  if (!script_state->ContextIsValid()) {
    exception_state.ThrowDOMException(DOMExceptionCode::kInvalidStateError,
                                      "The execution context is not valid.");
    return ScriptPromise();
  }

  // Connect to font access manager remote if not bound already.
  if (!remote_.is_bound()) {
    ExecutionContext* context = ExecutionContext::From(script_state);
    context->GetBrowserInterfaceBroker().GetInterface(
        remote_.BindNewPipeAndPassReceiver());
    remote_.set_disconnect_handler(
        WTF::Bind(&FontAccess::OnDisconnect, WrapWeakPersistent(this)));
  }
  DCHECK(remote_.is_bound());

  auto* resolver = MakeGarbageCollected<ScriptPromiseResolver>(script_state);
  ScriptPromise promise = resolver->Promise();
  remote_->EnumerateLocalFonts(resolver->WrapCallbackInScriptScope(
      WTF::Bind(&FontAccess::DidGetEnumerationResponse,
                WrapWeakPersistent(this), WrapPersistent(options))));

  return promise;
}

void FontAccess::DidGetEnumerationResponse(
    const QueryOptions* options,
    ScriptPromiseResolver* resolver,
    FontEnumerationStatus status,
    base::ReadOnlySharedMemoryRegion region) {
  if (!resolver->GetScriptState()->ContextIsValid())
    return;

  if (RejectPromiseIfNecessary(status, resolver))
    return;

  // Return an empty font list if user has denied the permission request,
  // or it is not implemented for this platform.
  if (status == FontEnumerationStatus::kUnimplemented ||
      status == FontEnumerationStatus::kPermissionDenied) {
    HeapVector<Member<FontMetadata>> entries;
    resolver->Resolve(std::move(entries));
    return;
  }

  // Font data exists; process and fill in the data.
  base::ReadOnlySharedMemoryMapping mapping = region.Map();
  FontEnumerationTable table;

  if (mapping.size() > INT_MAX) {
    // Cannot deserialize without overflow.
    resolver->Reject(V8ThrowDOMException::CreateOrDie(
        resolver->GetScriptState()->GetIsolate(), DOMExceptionCode::kDataError,
        "Font data exceeds memory limit."));
    return;
  }

  // Used to compare with data coming from the browser to avoid conversions.
  const bool hasPostscriptNameFilter = options->hasPostscriptNames();
  std::set<std::string> selection_utf8;
  if (hasPostscriptNameFilter) {
    for (const String& postscriptName : options->postscriptNames()) {
      // While postscript names are encoded in a subset of ASCII, we convert the
      // input into UTF8. This will still allow exact matches to occur.
      selection_utf8.insert(postscriptName.Utf8());
    }
  }

  HeapVector<Member<FontMetadata>> entries;
  table.ParseFromArray(mapping.memory(), static_cast<int>(mapping.size()));
  for (const auto& element : table.fonts()) {
    // If the optional postscript name filter is set in QueryOptions,
    // only allow items that match.
    if (hasPostscriptNameFilter &&
        selection_utf8.find(element.postscript_name().c_str()) ==
            selection_utf8.end())
      continue;

    FontEnumerationEntry entry = {};
    entry.postscript_name = String::FromUTF8(element.postscript_name().c_str());
    entry.full_name = String::FromUTF8(element.full_name().c_str());
    entry.family = String::FromUTF8(element.family().c_str());
    entry.style = String::FromUTF8(element.style().c_str());
    entries.push_back(FontMetadata::Create(std::move(entry)));
  }

  resolver->Resolve(std::move(entries));
}

bool FontAccess::RejectPromiseIfNecessary(const FontEnumerationStatus& status,
                                          ScriptPromiseResolver* resolver) {
  switch (status) {
    case FontEnumerationStatus::kOk:
    case FontEnumerationStatus::kUnimplemented:
    case FontEnumerationStatus::kPermissionDenied:
      break;
    case FontEnumerationStatus::kNeedsUserActivation:
      resolver->Reject(V8ThrowDOMException::CreateOrDie(
          resolver->GetScriptState()->GetIsolate(),
          DOMExceptionCode::kSecurityError, "User activation is required."));
      return true;
    case FontEnumerationStatus::kNotVisible:
      resolver->Reject(V8ThrowDOMException::CreateOrDie(
          resolver->GetScriptState()->GetIsolate(),
          DOMExceptionCode::kSecurityError, "Page needs to be visible."));
      return true;
    case FontEnumerationStatus::kUnexpectedError:
    default:
      resolver->Reject(V8ThrowDOMException::CreateOrDie(
          resolver->GetScriptState()->GetIsolate(),
          DOMExceptionCode::kUnknownError, "An unexpected error occured."));
      return true;
  }
  return false;
}

void FontAccess::OnDisconnect() {
  remote_.reset();
}

}  // namespace blink
