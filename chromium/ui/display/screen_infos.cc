// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/display/screen_infos.h"

#include "base/ranges/algorithm.h"

namespace display {

ScreenInfos::ScreenInfos() = default;
ScreenInfos::ScreenInfos(const ScreenInfo& screen_info)
    : screen_infos{screen_info}, current_display_id(screen_info.display_id) {}
ScreenInfos::ScreenInfos(const ScreenInfos& other) = default;
ScreenInfos::~ScreenInfos() = default;
ScreenInfos& ScreenInfos::operator=(const ScreenInfos& other) = default;
bool ScreenInfos::operator==(const ScreenInfos& other) const {
  return screen_infos == other.screen_infos &&
         current_display_id == other.current_display_id &&
         system_cursor_size == other.system_cursor_size;
}

bool ScreenInfos::operator!=(const ScreenInfos& other) const {
  return !operator==(other);
}

ScreenInfo& ScreenInfos::mutable_current() {
  return const_cast<ScreenInfo&>(
      const_cast<const ScreenInfos*>(this)->current());
}

const ScreenInfo& ScreenInfos::current() const {
  auto current_screen_info = screen_infos.cbegin();
  while (current_screen_info != screen_infos.cend() && current_screen_info->display_id != current_display_id)
    ++current_screen_info;
//   const auto& current_screen_info = base::ranges::find(
//       screen_infos, current_display_id, &ScreenInfo::display_id);
  CHECK(current_screen_info != screen_infos.cend());
  return *current_screen_info;
}

}  // namespace display
