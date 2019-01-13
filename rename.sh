#!/bin/bash

# rename.sh - Rename Kaleidoscope plugin files and components.
# Copyright (C) 2019 Jared Lindsay
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

function print_instructions {
  echo "rename.sh - Rename plugin files and components."
  echo "Usage: ./rename <new_plugin_name> [Author] [Description]"
  echo
  echo "NOTES: Omit the \"Kaleidoscope-\" prefix."
  echo "       The plugin name must be a single word."
  echo "       [Author] and [Description] should be enclosed in quotes."
}

if [ $# -eq 0 ] || [ $# -gt 2 ]  # No or too many arguments; print instructions.
then
  print_instructions
else  # We at least have the new plugin name.
  if [ ! -z "$2" ]  # Store author, if supplied.
  then
    author=$(printf %q "$2")  # `eval`, used later, needs the spaces escaped.
  fi

  if [ ! -z "$3" ]  # Store description, if supplied.
  then
    description=$(printf %q "$3")
  fi

  new_plugin_name=$1  # No quotes, since the plugin name must be a single word.
  prefix="Kaleidoscope"
  old_plugin_name="BlankPlugin"

  # Rename the files.
  mv src/$prefix-$old_plugin_name.h src/$prefix-$new_plugin_name.h
  mv src/Kaleidoscope/$old_plugin_name.h src/Kaleidoscope/$new_plugin_name.h
  mv src/Kaleidoscope/$old_plugin_name.cpp src/Kaleidoscope/$new_plugin_name.cpp

  # Use the right sed syntax, depending on the OS.
  if [ "$(uname -s)" == "Linux" ]
  then
    sed="sed -i"
  else
    sed="sed -i ''"
  fi

  # Change occurrences of 'BlankPlugin' to $new_plugin_name
  for file in library.properties\
              src/$prefix-$new_plugin_name.h\
              src/Kaleidoscope/$new_plugin_name.h\
              src/Kaleidoscope/$new_plugin_name.cpp
  do
    eval $sed s/$old_plugin_name/$new_plugin_name/g $file
    eval $sed "s/\<AUTHOR\>/$author/g" $file
    eval $sed "s/\<DESCRIPTION\>/$description/g" $file
  done
fi