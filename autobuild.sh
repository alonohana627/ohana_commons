#!/bin/sh

CC=gcc meson setup build --reconfigure -Dbuildtype=debug
meson compile -C build