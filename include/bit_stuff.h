#ifndef BIT_STUFF_H
#define BIT_STUFF_H
#include <stddef.h>

// bit commons
// some basic stuff from Hacker's Delight
#define TURN_OFF_RIGHTMOST_BIT(x) x &(x - 1)
#define TURN_ON_RIGHTMOST_BIT(x) x | (x + 1)
#define TURN_OFF_TRAILING(x) x &(x + 1)
#define TURN_ON_TRAILING(x) x |(x - 1)
// TODO: continue page 28


size_t find_next_power_of_two(size_t number);

#endif // BIT_STUFF_H