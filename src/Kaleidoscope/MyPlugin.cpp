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

// Runs once, when the plugin is initialized during Kaleidoscope.setup().
EventHandlerResult MyPlugin::onSetup() {
  // Code goes here.
}

// Run as the first thing at the start of each cycle.
EventHandlerResult MyPlugin::beforeEachCycle() {
  // Code goes here.
}

// Run for every non-idle key, in each cycle the key isn't idle in. If a key
// gets pressed, released, or is held, it is not considered idle, and this
// event handler will run for it too.
EventHandlerResult MyPlugin::onKeyswitchEvent(Key &mapped_key, byte row,
                                              byte col, int8_t key_state) {
  // Code goes here.
}

// Runs each cycle right before sending the various reports (keys pressed, mouse
// events, etc) to the host.
EventHandlerResult MyPlugin::beforeReportingState() {
  // Code goes here.
}

// Runs at the very end of each cycle.
EventHandlerResult MyPlugin::afterEachCycle() {
  // Code goes here.
}

}  // namespace plugin
}  // namespace kaleidoscope