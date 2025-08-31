#include "dynamic_str.h"
#include "internal_handle.h"
#include "ohana_commons.h"
#include <string.h>

oc_dynamic_str_t *oc_dynamic_str_init(char *c) {
  size_t len = strlen(c);
  size_t capacity = find_next_power_of_two(len + 1);
  capacity = capacity >= MIN_SIZE ? capacity : MIN_SIZE;

  oc_dynamic_str_t *ds = malloc(sizeof(oc_dynamic_str_t));
  if (!ds)
    return NULL;

  ds->str = malloc(capacity);
  if (!ds->str) {
    free(ds);
    return NULL;
  }

  memcpy(ds->str, c, len);
  ds->str[len] = '\0';

  ds->len = len;
  ds->capacity = capacity;

  return ds;
}

int oc_dynamic_str_destroy(oc_dynamic_str_t **dyn_str) {
  if (!dyn_str || !*dyn_str)
    return -1;

  oc_dynamic_str_t *ds = *dyn_str;
  free(ds->str);
  ds->str = NULL;
  ds->len = 0;
  ds->capacity = 0;

  free(ds);
  *dyn_str = NULL; // prevent dangling pointer

  return 0;
}

int _internal_ohcommon oc_dynamic_str_resize(oc_dynamic_str_t *s, size_t new_len) {
  if (!s)
    return -1;

  size_t needed = new_len + 1; // include '\0'
  if (needed > s->capacity) {
    size_t new_cap = find_next_power_of_two(needed);
    char *new_buf = realloc(s->str, new_cap);
    if (!new_buf) {
      return -1;
    }

    s->str = new_buf;
    s->capacity = new_cap;
  }

  if (new_len > s->len) {
    // zero-fill the new region
    memset(s->str + s->len, 0, new_len - s->len);
  }

  s->len = new_len;
  s->str[new_len] = '\0';
  return 0;
}

size_t oc_dynamic_str_get_capacity(oc_dynamic_str_t *s) {
  return s ? s->capacity : 0;
}

char *oc_dynamic_str_cstr(oc_dynamic_str_t *s) { return s ? s->str : NULL; }

size_t oc_dynamic_str_len(oc_dynamic_str_t *s) { return s ? s->len : 0; }

int oc_dynamic_str_append(oc_dynamic_str_t *s, const char *suffix) {
    if (!s || !suffix) return -1;

    size_t add_len = strlen(suffix);
    size_t new_len = s->len + add_len;

    // ensure capacity for new_len + '\0'
    if (oc_dynamic_str_resize(s, new_len) != 0) {
        return -1; // failed realloc
    }

    // copy suffix into place
    memcpy(s->str + (new_len - add_len), suffix, add_len);

    // len already set by resize()
    return 0;
}

int oc_dynamic_str_chop(oc_dynamic_str_t *s, size_t count) {
    if (!s) {
      return -1;
    }

    if (count >= s->len) {
        // chop more than length → becomes empty
        return oc_dynamic_str_resize(s, 0);
    }

    size_t new_len = s->len - count;
    return oc_dynamic_str_resize(s, new_len);
}
