// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/signin/chrome_signin_client_factory.h"

#ifndef TOOLKIT_QT
#include "chrome/browser/net/profile_network_context_service_factory.h"
#endif
#include "chrome/browser/profiles/profile.h"
#include "components/keyed_service/content/browser_context_dependency_manager.h"

ChromeSigninClientFactory::ChromeSigninClientFactory()
    : BrowserContextKeyedServiceFactory(
          "ChromeSigninClient",
          BrowserContextDependencyManager::GetInstance()) {
#ifndef TOOLKIT_QT
  DependsOn(ProfileNetworkContextServiceFactory::GetInstance());
#endif
}

ChromeSigninClientFactory::~ChromeSigninClientFactory() {}

// static
SigninClient* ChromeSigninClientFactory::GetForProfile(Profile* profile) {
  return static_cast<SigninClient*>(
      GetInstance()->GetServiceForBrowserContext(profile, true));
}

// static
ChromeSigninClientFactory* ChromeSigninClientFactory::GetInstance() {
  return base::Singleton<ChromeSigninClientFactory>::get();
}

KeyedService* ChromeSigninClientFactory::BuildServiceInstanceFor(
    content::BrowserContext* context) const {
  return new ChromeSigninClient(Profile::FromBrowserContext(context));
}
