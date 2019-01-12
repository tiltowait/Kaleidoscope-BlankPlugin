# Kaleidoscope-BlankPlugin

A blank plugin template for [Kaleidoscope](https://github.com/keyboardio/Kaleidoscope). Provides everything needed to easily get started writing a new plugin, including a utility for rapid rename.

## `rename.sh`

`rename.sh` is a special utility for easily and quickly renaming your files, changing the plugin name, adding author credit, and inserting a description. It uses the following syntax:

```shell
./rename.sh <new_plugin_name> [Author] [Description]
```

### `new_plugin_name`

The name of the new plugin. Note that this *must* be a single word. Also, you should omit the `Kaleidoscope-` prefix; it will be added for you where necessary.

- **Good:** `FooBar`
- **Bad:** `Foo Bar`, `Kaleidoscope-FooBar`

Your plugin [files](#files) will be renamed to fit the specified plugin name. For instance, `Kaleidoscope-BlankPlugin.h` will become `Kaleidoscope-FooBar.h`.

### `Author`

An optional argument, `Author` will replace the `<AUTHOR>` line near the beginning of each file. Additionally, `Author` should be enclosed in spaces if it's longer than one word.

- **Good:** `"Billy Sanchez"`
- **Bad:** `Billy Sanchez`

If you don't use quotes, `Author` will simply become `Billy`, leaving `Sanchez` for [`Description`](#description).

### `Description`

Another optional argument, this one behaves much the same as [`Author`](#author), only it replaces the `<DESCRIPTION>` tag in the plugin files.

## Files

### `Kaleidoscope-BlankPlugin.h`

> The base header for your plugin. It shouldn't have any code; instead, it should simply `#include Kaleidoscope/Plugin.h`.

### `BlankPlugin.h`

> The main header for your plugin.

### `BlankPlugin.cpp`

> Where all the magic happens.

## Event Handlers

Kaleidoscope plugins have several event handlers, special methods the plugin system calls at certain times during each keyboard cycle. Implementing these methods is how your plugin will augment keyboard behavior. (Taken directly from the [glossary](https://github.com/keyboardio/Kaleidoscope/blob/master/doc/glossary.md))

 - `onSetup`: Run once, when the plugin is initialised during
   `Kaleidoscope.setup()`.
 - `beforeEachCycle`: Run as the first thing at the start of each [cycle](#cycle).
 - `onKeyswitchEvent`: Run for every non-idle key, in each [cycle](#cycle) the
   key isn't idle in. If a key gets pressed, released, or is held, it is not
   considered idle, and this event handler will run for it too.
 - `beforeReportingState`: Runs each [cycle](#cycle) right before sending the
   various reports (keys pressed, mouse events, etc) to the host.
 - `afterEachCycle`: Runs at the very end of each [cycle](#cycle).