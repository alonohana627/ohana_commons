#include <assert.h>
#include <string.h>
#include <ohana_commons.h>   // your dynamic string APIs

int main(void) {
    // --- basic append ---
    oc_dynamic_str_t *s1 = oc_dynamic_str_init("hello");
    assert(s1 != NULL);
    assert(oc_dynamic_str_append(s1, " world") == 0);
    assert(strcmp(oc_dynamic_str_cstr(s1), "hello world") == 0);
    assert(oc_dynamic_str_len(s1) == strlen("hello world"));
    oc_dynamic_str_destroy(&s1);

    // --- append to empty string ---
    oc_dynamic_str_t *s2 = oc_dynamic_str_init("");
    assert(oc_dynamic_str_append(s2, "foo") == 0);
    assert(strcmp(oc_dynamic_str_cstr(s2), "foo") == 0);
    assert(oc_dynamic_str_len(s2) == 3);
    oc_dynamic_str_destroy(&s2);

    // --- multiple appends ---
    oc_dynamic_str_t *s3 = oc_dynamic_str_init("a");
    assert(oc_dynamic_str_append(s3, "b") == 0);
    assert(oc_dynamic_str_append(s3, "c") == 0);
    assert(strcmp(oc_dynamic_str_cstr(s3), "abc") == 0);
    assert(oc_dynamic_str_len(s3) == 3);
    oc_dynamic_str_destroy(&s3);

    // --- capacity growth ---
    oc_dynamic_str_t *s4 = oc_dynamic_str_init("x");
    size_t old_cap = oc_dynamic_str_get_capacity(s4);
    char big[1024];
    memset(big, 'y', sizeof(big) - 1);
    big[sizeof(big) - 1] = '\0';
    assert(oc_dynamic_str_append(s4, big) == 0);
    assert(oc_dynamic_str_len(s4) == 1 + strlen(big));
    assert(s4->capacity > old_cap); // capacity must have grown
    oc_dynamic_str_destroy(&s4);

    // --- append empty string (should no-op) ---
    oc_dynamic_str_t *s5 = oc_dynamic_str_init("foo");
    assert(oc_dynamic_str_append(s5, "") == 0);
    assert(strcmp(oc_dynamic_str_cstr(s5), "foo") == 0);
    assert(oc_dynamic_str_len(s5) == 3);
    oc_dynamic_str_destroy(&s5);

    // --- append NULL suffix (error) ---
    oc_dynamic_str_t *s6 = oc_dynamic_str_init("bar");
    assert(oc_dynamic_str_append(s6, NULL) == -1);
    oc_dynamic_str_destroy(&s6);

    return 0;
}
