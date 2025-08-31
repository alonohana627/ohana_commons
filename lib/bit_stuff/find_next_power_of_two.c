#include <ohana_commons.h>

// https://graphics.stanford.edu/%7Eseander/bithacks.html#RoundUpPowerOf2
size_t find_next_power_of_two(size_t v){
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}