#!/bin/sh

# Run from Docker
apt update
apt install build-essential meson ninja-build valgrind -y
