#!/bin/sh

# run after autobuild.sh

################### Dynamic Strings ###################
valgrind -s \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --track-fds=yes \
  --errors-for-leak-kinds=all \
  --error-exitcode=1 \
  ./build/tests/test_oc_dynamic_str_init

valgrind -s \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --track-fds=yes \
  --errors-for-leak-kinds=all \
  --error-exitcode=1 \
  ./build/tests/test_oc_dynamic_str_destroy

valgrind -s \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --track-fds=yes \
  --errors-for-leak-kinds=all \
  --error-exitcode=1 \
  ./build/tests/test_oc_dynamic_str_resize

valgrind -s \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --track-fds=yes \
  --errors-for-leak-kinds=all \
  --error-exitcode=1 \
  ./build/tests/test_oc_dynamic_str_chop

valgrind -s \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --track-fds=yes \
  --errors-for-leak-kinds=all \
  --error-exitcode=1 \
  ./build/tests/test_oc_dynamic_str_append