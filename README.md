# Kaleidoscope-MyPlugin

A blank plugin template for [Kaleidoscope](https://github.com/keyboardio/Kaleidoscope). Provides everything needed to easily get started writing a new plugin.

## Files

### `Kaleidoscope-MyPlugin.h`

> The base header for your plugin. It shouldn't have any code; instead, it should simply `#include Kaleidoscope/Plugin.h`.

### `MyPlugin.h`

> The main header for your plugin.

### `MyPlugin.cpp`

> Where all the magic happens.

## Event Handlers

Kaleidoscope plugins have several event handlers, special methods the plugin system calls at certain times during each keyboard cycle. Implementing these methods is how your plugin will augment keyboard behavior.

 - `onSetup`: Run once, when the plugin is initialised during
   `Kaleidoscope.setup()`.
 - `beforeEachCycle`: Run as the first thing at the start of each [cycle](#cycle).
 - `onKeyswitchEvent`: Run for every non-idle key, in each [cycle](#cycle) the
   key isn't idle in. If a key gets pressed, released, or is held, it is not
   considered idle, and this event handler will run for it too.
 - `beforeReportingState`: Runs each [cycle](#cycle) right before sending the
   various reports (keys pressed, mouse events, etc) to the host.
 - `afterEachCycle`: Runs at the very end of each [cycle](#cycle).