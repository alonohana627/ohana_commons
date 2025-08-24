#include <assert.h>
#include <string.h>
#include <ohana_commons.h>   // oc_dynamic_str_* APIs

int main(void) {
    // --- grow from small string ---
    oc_dynamic_str_t *s1 = oc_dynamic_str_init("abc");
    assert(s1 != NULL);
    assert(oc_dynamic_str_len(s1) == 3);

    int rc = oc_dynamic_str_resize(s1, 10);
    assert(rc == 0);
    assert(oc_dynamic_str_len(s1) == 10);
    assert(oc_dynamic_str_cstr(s1)[3] == '\0'); // old "abc" cut off
    assert(oc_dynamic_str_cstr(s1)[9] == '\0'); // new null terminator
    assert(oc_dynamic_str_get_capacity(s1) >= 11);

    oc_dynamic_str_destroy(&s1);

    // --- shrink down ---
    oc_dynamic_str_t *s2 = oc_dynamic_str_init("abcdefghij");
    assert(s2 != NULL);
    rc = oc_dynamic_str_resize(s2, 5);
    assert(rc == 0);
    assert(oc_dynamic_str_len(s2) == 5);
    assert(strcmp(oc_dynamic_str_cstr(s2), "abcde") == 0);

    oc_dynamic_str_destroy(&s2);

    // --- resize to zero ---
    oc_dynamic_str_t *s3 = oc_dynamic_str_init("hello");
    rc = oc_dynamic_str_resize(s3, 0);
    assert(rc == 0);
    assert(oc_dynamic_str_len(s3) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s3), "") == 0);
    assert(oc_dynamic_str_get_capacity(s3) >= 1);

    oc_dynamic_str_destroy(&s3);

    // --- grow multiple times (capacity should double) ---
    oc_dynamic_str_t *s4 = oc_dynamic_str_init("x");
    size_t cap_before = oc_dynamic_str_get_capacity(s4);
    rc = oc_dynamic_str_resize(s4, cap_before + 5);
    assert(rc == 0);
    assert(oc_dynamic_str_get_capacity(s4) >= cap_before * 2);

    oc_dynamic_str_destroy(&s4);

    // --- resize no-op (same length) ---
    oc_dynamic_str_t *s5 = oc_dynamic_str_init("foo");
    rc = oc_dynamic_str_resize(s5, 3);
    assert(rc == 0);
    assert(strcmp(oc_dynamic_str_cstr(s5), "foo") == 0);
    assert(oc_dynamic_str_len(s5) == 3);

    oc_dynamic_str_destroy(&s5);

    return 0;
}
