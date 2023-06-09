// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/gl/gpu_switching_manager.h"

#include "base/observer_list.h"

namespace ui {

// static
GpuSwitchingManager* GpuSwitchingManager::GetInstance() {
  return base::Singleton<GpuSwitchingManager>::get();
}

GpuSwitchingManager::GpuSwitchingManager() {}

GpuSwitchingManager::~GpuSwitchingManager() {}

void GpuSwitchingManager::AddObserver(GpuSwitchingObserver* observer) {
  base::AutoLock auto_lock(lock_);
  observer_list_.AddObserver(observer);
}

void GpuSwitchingManager::RemoveObserver(GpuSwitchingObserver* observer) {
  base::AutoLock auto_lock(lock_);
  observer_list_.RemoveObserver(observer);
}

void GpuSwitchingManager::NotifyGpuSwitched(
    gl::GpuPreference active_gpu_heuristic) {
  base::AutoLock auto_lock(lock_);
  for (GpuSwitchingObserver& observer : observer_list_)
    observer.OnGpuSwitched(active_gpu_heuristic);
}

void GpuSwitchingManager::NotifyDisplayAdded() {
  base::AutoLock auto_lock(lock_);
  for (GpuSwitchingObserver& observer : observer_list_)
    observer.OnDisplayAdded();
}

void GpuSwitchingManager::NotifyDisplayRemoved() {
  base::AutoLock auto_lock(lock_);
  for (GpuSwitchingObserver& observer : observer_list_)
    observer.OnDisplayRemoved();
}

void GpuSwitchingManager::NotifyDisplayMetricsChanged() {
  base::AutoLock auto_lock(lock_);
  for (GpuSwitchingObserver& observer : observer_list_)
    observer.OnDisplayMetricsChanged();
}

}  // namespace ui
