#include <stdint.h>

void _exit(int status) {
    // Your custom exit code here
    while (1) {}  // Loop indefinitely or perform other shutdown tasks
}

void delay_ms(uint32_t ms) {
    uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 3180; j++) {

        }
    }
}

int main(void) {
    // Enable the clock to GPIO Port F
    *((unsigned int *)0x400FE608U) = 0x20U;
    // Set the direction of PF1 as output
    *((unsigned int *)0x40025400U) = 0x02U;
    while (1) {
        // Turn on the LED connected to PF1
        *((unsigned int *)0x400253FCU) = 0x02U;
        delay_ms(1000);
        // Turn off the LED connected to PF1
        *((unsigned int *)0x400253FCU) = 0x00U;
        delay_ms(1000);
    }
    return 0;
}