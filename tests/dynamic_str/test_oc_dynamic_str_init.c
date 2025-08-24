#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ohana_commons.h>   // your struct + prototypes

// assume MIN_SIZE = 16

int main(void) {
    // --- basic init ---
    oc_dynamic_str_t *ds = oc_dynamic_str_init("hello");
    assert(ds != NULL);
    assert(strcmp(ds->str, "hello") == 0);
    assert(ds->len == 5);
    assert(ds->capacity >= 6);    // must fit "hello\0"
    assert(ds->capacity >= MIN_SIZE);
    free(ds->str);
    free(ds);

    // --- empty string ---
    ds = oc_dynamic_str_init("");
    assert(ds != NULL);
    assert(strcmp(ds->str, "") == 0);
    assert(ds->len == 0);
    assert(ds->capacity >= 1);    // must fit '\0'
    assert(ds->capacity >= MIN_SIZE);
    free(ds->str);
    free(ds);

    // --- exact power of two length ---
    char buf[8+1]; // 8 chars + '\0'
    memset(buf, 'a', 8);
    buf[8] = '\0';
    ds = oc_dynamic_str_init(buf);
    assert(ds != NULL);
    assert(ds->len == 8);
    assert(strcmp(ds->str, buf) == 0);
    assert(ds->capacity >= 9);    // must fit 8 chars + '\0'
    free(ds->str);
    free(ds);

    // --- just below a power of two ---
    char buf2[15+1]; // 15 chars
    memset(buf2, 'b', 15);
    buf2[15] = '\0';
    ds = oc_dynamic_str_init(buf2);
    assert(ds != NULL);
    assert(ds->len == 15);
    assert(strcmp(ds->str, buf2) == 0);
    assert(ds->capacity >= 16);   // expect rounded to 16 or above
    free(ds->str);
    free(ds);

    // --- larger string ---
    char big[1000+1];
    memset(big, 'x', 1000);
    big[1000] = '\0';
    ds = oc_dynamic_str_init(big);
    assert(ds != NULL);
    assert(ds->len == 1000);
    assert(strcmp(ds->str, big) == 0);
    assert(ds->capacity == 1024); // should round up to 1024
    free(ds->str);
    free(ds);

    return 0;
}
