#ifndef DYNAMIC_STR_H
#define DYNAMIC_STR_H

#include <stddef.h>
#include <stdlib.h>
#include "internal_handle.h"

#define MIN_SIZE 16

typedef struct {
  char *str;       // heap buffer, always null-terminated
  size_t len;      // current string length (without '\0')
  size_t capacity; // allocated buffer size (including space for '\0')
} oc_dynamic_str_t;

// Minhalot of memories
oc_dynamic_str_t *oc_dynamic_str_init(char *c);
int oc_dynamic_str_destroy(oc_dynamic_str_t **dyn_str);
int _internal_ohcommon oc_dynamic_str_resize(oc_dynamic_str_t *s, size_t new_len);

// Getters
size_t oc_dynamic_str_get_capacity(oc_dynamic_str_t *s);
char *oc_dynamic_str_cstr(oc_dynamic_str_t *s);
size_t oc_dynamic_str_len(oc_dynamic_str_t *s);

// simple append and chop
int oc_dynamic_str_append(oc_dynamic_str_t *s, const char *suffix);
int oc_dynamic_str_chop(oc_dynamic_str_t *s, size_t count);

#endif
