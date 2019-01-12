/* -*- mode: c++ -*-
 * Kaleidoscope-MyPlugin - Does something ...
 * Copyright (C) 2019 J P Codington
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Kaleidoscope-MyPlugin.h>

namespace kaleidoscope {
namespace plugin {

// MyPlugin

// Member variables.
bool MyPlugin::disabled_ = false;

// Basic plugin status functions.

// Enable the plugin.
void MyPlugin::enable() {
  disabled_ = false;
}

// Disable the plugin.
void MyPlugin::disable() {
  disabled_ = true;
}

// Returns true if the plugin is enabled.
void MyPlugin::active() {
  return !disabled_;
}

// Event handlers.

// Runs once, when the plugin is initialized during Kaleidoscope.setup().
EventHandlerResult MyPlugin::onSetup() {
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run as the first thing at the start of each cycle.
EventHandlerResult MyPlugin::beforeEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run for every non-idle key, in each cycle the key isn't idle in. If a key
// gets pressed, released, or is held, it is not considered idle, and this
// event handler will run for it too.
EventHandlerResult MyPlugin::onKeyswitchEvent(Key &mapped_key, byte row,
                                              byte col, int8_t key_state) {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs each cycle right before sending the various reports (keys pressed, mouse
// events, etc) to the host.
EventHandlerResult MyPlugin::beforeReportingState() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs at the very end of each cycle.
EventHandlerResult MyPlugin::afterEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

}  // namespace plugin
}  // namespace kaleidoscope