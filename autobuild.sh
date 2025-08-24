#!/bin/sh

CC=gcc meson setup build --reconfigure -Dbuildtype=debug
CC=gcc meson compile -C build

# Runs the tests
CC=gcc meson test -C build
