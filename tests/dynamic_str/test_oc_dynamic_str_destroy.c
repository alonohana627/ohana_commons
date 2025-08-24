#include <assert.h>
#include <string.h>
#include <ohana_commons.h>   // oc_dynamic_str_t, init, destroy

int main(void) {
    // --- normal destroy ---
    oc_dynamic_str_t *s1 = oc_dynamic_str_init("hello");
    assert(s1 != NULL);
    assert(strcmp(s1->str, "hello") == 0);
    int rc = oc_dynamic_str_destroy(&s1);
    assert(rc == 0);
    assert(s1 == NULL);   // must be NULL after destroy

    // --- double destroy (must be safe) ---
    rc = oc_dynamic_str_destroy(&s1);
    assert(rc == -1);     // already NULL, returns error
    assert(s1 == NULL);   // still NULL

    // --- destroy NULL pointer ---
    rc = oc_dynamic_str_destroy(NULL);
    assert(rc == -1);

    // --- destroy empty string ---
    oc_dynamic_str_t *s2 = oc_dynamic_str_init("");
    assert(s2 != NULL);
    assert(strcmp(s2->str, "") == 0);
    rc = oc_dynamic_str_destroy(&s2);
    assert(rc == 0);
    assert(s2 == NULL);

    // --- destroy long string (to stress capacity + free) ---
    char buf[1024];
    memset(buf, 'x', 1023);
    buf[1023] = '\0';
    oc_dynamic_str_t *s3 = oc_dynamic_str_init(buf);
    assert(s3 != NULL);
    assert(s3->len == 1023);
    assert(strcmp(s3->str, buf) == 0);
    rc = oc_dynamic_str_destroy(&s3);
    assert(rc == 0);
    assert(s3 == NULL);

    return 0;
}