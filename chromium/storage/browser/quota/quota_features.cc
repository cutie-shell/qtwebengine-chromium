// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "storage/browser/quota/quota_features.h"
#include "base/feature_list.h"

namespace storage {

namespace features {

namespace {
constexpr int64_t kMBytes = 1024 * 1024;
}  // namespace

// Enables Storage Pressure Event.
const base::Feature kStoragePressureEvent{"StoragePressureEvent",
                                          base::FEATURE_DISABLED_BY_DEFAULT};

// Enables customized storage quota settings for embedders.
const base::Feature kStorageQuotaSettings{"StorageQuotaSettings",
                                          base::FEATURE_DISABLED_BY_DEFAULT};
const base::FeatureParam<double> kMustRemainAvailableBytes{
    &kStorageQuotaSettings, "MustRemainAvailableBytes", 1024 * kMBytes /* 1GB */
};
const base::FeatureParam<double> kMustRemainAvailableRatio{
    &kStorageQuotaSettings, "MustRemainAvailableRatio", 0.01 /* 1% */
};
const base::FeatureParam<double> kPoolSizeBytes{&kStorageQuotaSettings,
                                                    "PoolSizeBytes", 0};
const base::FeatureParam<double> kPoolSizeRatio{
    &kStorageQuotaSettings, "PoolSizeRatio", 0.8 /* 80% */
};
const base::FeatureParam<double> kShouldRemainAvailableBytes{
    &kStorageQuotaSettings, "ShouldRemainAvailableBytes",
    2048 * kMBytes /* 2GB */
};
const base::FeatureParam<double> kShouldRemainAvailableRatio{
    &kStorageQuotaSettings, "ShouldRemainAvailableRatio", 0.1 /* 10% */
};

// Whether the StoragePolicyObserver only sends updates for modified origins.
const base::Feature kOnlySendStoragePolicyUpdatesForModifiedOrigins{
    "OnlySendStoragePolicyUpdatesForModifiedOrigins",
    base::FEATURE_ENABLED_BY_DEFAULT};

}  // namespace features
}  // namespace storage
