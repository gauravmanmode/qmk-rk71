#include "gpio.h"
#include "sh68f90a.h"
#include <stdint.h>

/*

# Rows
P7_1 - R0
P7_2 - R1
P7_3 - R2
P5_3 - R3
P5_4 - R4

# Columns
P6_0 - C0
P6_1 - C1
P6_2 - C2
P6_3 - C3
P6_4 - C4
P6_5 - C5
P6_6 - C6
P6_7 - C7
P5_0 - C8
P5_1 - C9
P5_2 - C10
P5_7 - C11
P4_0 - C12
P4_2 - C13

# LEDs
not traced

*/

void gpio_init()
{
    // I set this up by following the same pattern done in the original and it works, I don't really understand the meaning of this "registers" :D... looks like registers/bits need to be turned "on" for the ports being used.
    
    P5 = (uint8_t)(_P5_0 | _P5_1 | _P5_2 | _P5_7);
    P5CR = (uint8_t)(_P5_0 | _P5_1 | _P5_2 | _P5_7);
    P5PCR = (uint8_t)(_P5_0 | _P5_1 | _P5_2 | _P5_3 | _P5_4 | _P5_7);

    P7PCR = (uint8_t)(_P7_1 | _P7_2 | _P7_3);

    P6 = (uint8_t)(_P6_0 | _P6_1 | _P6_2 | _P6_3 | _P6_4 | _P6_5 | _P6_6 | _P6_7);
    P6CR = (uint8_t)(_P6_0 | _P6_1 | _P6_2 | _P6_3 | _P6_4 | _P6_5 | _P6_6 | _P6_7);
    P6PCR = (uint8_t)(_P6_0 | _P6_1 | _P6_2 | _P6_3 | _P6_4 | _P6_5 | _P6_6 | _P6_7);

    P4 = (uint8_t)(_P4_0 | _P4_2);
    P4CR = (uint8_t)(_P4_0 | _P4_2);
    P4PCR = (uint8_t)(_P4_0 | _P4_2);
}

