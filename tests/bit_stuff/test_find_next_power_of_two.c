#include <stdio.h>
#include <ohana_commons.h>
#include <assert.h>

int main() {
    assert(find_next_power_of_two(0) == 0);
    assert(find_next_power_of_two(1) == 1);
    assert(find_next_power_of_two(2) == 2);

    assert(find_next_power_of_two(4) == 4);
    assert(find_next_power_of_two(8) == 8);
    assert(find_next_power_of_two(16) == 16);
    assert(find_next_power_of_two(1024) == 1024);

    assert(find_next_power_of_two(3) == 4);
    assert(find_next_power_of_two(7) == 8);
    assert(find_next_power_of_two(15) == 16);
    assert(find_next_power_of_two(31) == 32);
    assert(find_next_power_of_two(63) == 64);
    assert(find_next_power_of_two(127) == 128);

    assert(find_next_power_of_two(5) == 8);
    assert(find_next_power_of_two(9) == 16);
    assert(find_next_power_of_two(17) == 32);
    assert(find_next_power_of_two(33) == 64);
    assert(find_next_power_of_two(65) == 128);

    assert(find_next_power_of_two(35) == 64);
    assert(find_next_power_of_two(70) == 128);
    assert(find_next_power_of_two(129) == 256);
    assert(find_next_power_of_two(1000) == 1024);
    assert(find_next_power_of_two(1500) == 2048);
    assert(find_next_power_of_two(4097) == 8192);
    return 0;
}
