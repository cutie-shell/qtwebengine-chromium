// Copyright 2018 The Dawn Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDE_DAWN_NATIVE_D3D12BACKEND_H_
#define INCLUDE_DAWN_NATIVE_D3D12BACKEND_H_

#include <dawn/dawn_wsi.h>
#include <dawn/native/DawnNative.h>

#include <DXGI1_4.h>
#include <d3d12.h>
#include <windows.h>
#include <wrl/client.h>

#include <memory>

struct ID3D12Device;
struct ID3D12Resource;

namespace dawn::native::d3d12 {

    class D3D11on12ResourceCache;
    class Device;
    class ExternalImageDXGIImpl;

    DAWN_NATIVE_EXPORT Microsoft::WRL::ComPtr<ID3D12Device> GetD3D12Device(WGPUDevice device);
    DAWN_NATIVE_EXPORT DawnSwapChainImplementation CreateNativeSwapChainImpl(WGPUDevice device,
                                                                             HWND window);
    DAWN_NATIVE_EXPORT WGPUTextureFormat
    GetNativeSwapChainPreferredFormat(const DawnSwapChainImplementation* swapChain);

    enum MemorySegment {
        Local,
        NonLocal,
    };

    DAWN_NATIVE_EXPORT uint64_t SetExternalMemoryReservation(WGPUDevice device,
                                                             uint64_t requestedReservationSize,
                                                             MemorySegment memorySegment);

    struct DAWN_NATIVE_EXPORT ExternalImageDescriptorDXGISharedHandle : ExternalImageDescriptor {
      public:
        ExternalImageDescriptorDXGISharedHandle();

        // Note: SharedHandle must be a handle to a texture object.
        HANDLE sharedHandle;
    };

    // Keyed mutex acquire/release uses a fixed key of 0 to match Chromium behavior.
    constexpr UINT64 kDXGIKeyedMutexAcquireReleaseKey = 0;

    struct DAWN_NATIVE_EXPORT ExternalImageAccessDescriptorDXGIKeyedMutex
        : ExternalImageAccessDescriptor {
      public:
        // TODO(chromium:1241533): Remove deprecated keyed mutex params after removing associated
        // code from Chromium - we use a fixed key of 0 for acquire and release everywhere now.
        uint64_t acquireMutexKey;
        uint64_t releaseMutexKey;
        bool isSwapChainTexture = false;
    };

    class DAWN_NATIVE_EXPORT ExternalImageDXGI {
      public:
        ~ExternalImageDXGI();

        static std::unique_ptr<ExternalImageDXGI> Create(
            WGPUDevice device,
            const ExternalImageDescriptorDXGISharedHandle* descriptor);

        // Returns true if the external image resources are still valid, otherwise ProduceTexture() is
        // guaranteed to fail e.g. after device destruction.
        bool IsValid() const;

        // TODO(sunnyps): |device| is ignored - remove after Chromium migrates to single parameter call.
        WGPUTexture ProduceTexture(WGPUDevice device,
                                   const ExternalImageAccessDescriptorDXGIKeyedMutex* descriptor);

        WGPUTexture ProduceTexture(const ExternalImageAccessDescriptorDXGIKeyedMutex* descriptor);

      private:
        explicit ExternalImageDXGI(std::unique_ptr<ExternalImageDXGIImpl> impl);

        std::unique_ptr<ExternalImageDXGIImpl> mImpl;
    };

    struct DAWN_NATIVE_EXPORT AdapterDiscoveryOptions : public AdapterDiscoveryOptionsBase {
        AdapterDiscoveryOptions();
        explicit AdapterDiscoveryOptions(Microsoft::WRL::ComPtr<IDXGIAdapter> adapter);

        Microsoft::WRL::ComPtr<IDXGIAdapter> dxgiAdapter;
    };

}  // namespace dawn::native::d3d12

#endif  // INCLUDE_DAWN_NATIVE_D3D12BACKEND_H_
