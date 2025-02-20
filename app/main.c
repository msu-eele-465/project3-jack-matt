#include <msp430.h>
#include <stdbool.h>

#include "heartbeat.h"
#include "keypad.h"

int main(void)
{
    // Stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    P1DIR |= BIT0; // configure LED2
    P1OUT &= ~BIT0;
    
    heartbeat_init();
    keypad_init();

    // Disable the GPIO power-on default high-impedance mdoe to activate
    // previously configure port settings
    PM5CTL0 &= ~LOCKLPM5;
    while (true) {
        keypad_scan(); // Check for keypresses
                    // Rest of your code...
    }
}