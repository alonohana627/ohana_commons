#include <assert.h>
#include <string.h>
#include <ohana_commons.h>   // oc_dynamic_str APIs

int main(void) {
    // --- basic chop ---
    oc_dynamic_str_t *s1 = oc_dynamic_str_init("hello");
    assert(s1 != NULL);
    assert(oc_dynamic_str_chop(s1, 2) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s1), "hel") == 0);
    assert(oc_dynamic_str_len(s1) == 3);
    oc_dynamic_str_destroy(&s1);

    // --- chop exactly length ---
    oc_dynamic_str_t *s2 = oc_dynamic_str_init("abc");
    assert(oc_dynamic_str_chop(s2, 3) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s2), "") == 0);
    assert(oc_dynamic_str_len(s2) == 0);
    oc_dynamic_str_destroy(&s2);

    // --- chop more than length ---
    oc_dynamic_str_t *s3 = oc_dynamic_str_init("xyz");
    assert(oc_dynamic_str_chop(s3, 100) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s3), "") == 0);
    assert(oc_dynamic_str_len(s3) == 0);
    oc_dynamic_str_destroy(&s3);

    // --- chop zero (no-op) ---
    oc_dynamic_str_t *s4 = oc_dynamic_str_init("unchanged");
    size_t old_len = oc_dynamic_str_len(s4);
    assert(oc_dynamic_str_chop(s4, 0) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s4), "unchanged") == 0);
    assert(oc_dynamic_str_len(s4) == old_len);
    oc_dynamic_str_destroy(&s4);

    // --- chop from empty string ---
    oc_dynamic_str_t *s5 = oc_dynamic_str_init("");
    assert(oc_dynamic_str_chop(s5, 5) == 0); // should stay empty
    assert(strcmp(oc_dynamic_str_cstr(s5), "") == 0);
    assert(oc_dynamic_str_len(s5) == 0);
    oc_dynamic_str_destroy(&s5);

    // --- chop large string repeatedly ---
    oc_dynamic_str_t *s6 = oc_dynamic_str_init("abcdefghijklmnopqrstuvwxyz");
    assert(s6 != NULL);
    assert(oc_dynamic_str_chop(s6, 10) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s6), "abcdefghijklmnop") == 0);
    assert(oc_dynamic_str_len(s6) == 16);
    assert(oc_dynamic_str_chop(s6, 16) == 0);
    assert(strcmp(oc_dynamic_str_cstr(s6), "") == 0);
    assert(oc_dynamic_str_len(s6) == 0);
    oc_dynamic_str_destroy(&s6);

    return 0;
}
