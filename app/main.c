#include <msp430.h>
#include <stdbool.h>

#include "heartbeat.h"
#include "keypad.h"
#include "LEDarray.h"

int main(void)
{
    // Stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    P1DIR |= BIT0; // configure LED2
    P1OUT &= ~BIT0;
    
    keypad_init();
    heartbeat_init();
    ledarray_init();
    ledarray_select_pattern(PATTERN_1_TOGGLE);

    // Disable the GPIO power-on default high-impedance mdoe to activate
    // previously configure port settings
    PM5CTL0 &= ~LOCKLPM5;
    int counterA = 0;
    int counterB = 0;
    while (true) {
        counterA++;
        if(counterA % 12 == 0){
            counterB = (counterB + 1) % 4;
            switch (counterB) {
                case 0:
                    ledarray_select_pattern(PATTERN_0_STATIC);
                    break;
                    
                case 1:
                    ledarray_select_pattern(PATTERN_1_TOGGLE);
                    break;
                    
                case 2:
                    ledarray_select_pattern(PATTERN_2_UP_COUNT);
                    break;
                    
                case 3:
                    ledarray_select_pattern(PATTERN_3_IN_OUT);
                    break;
                    
                default:
                    P3OUT |= LED_PINS;
                    break;
            }
        }
        // keypad_scan(); // Check for keypresses
                    // Rest of your code...
        ledarray_update();
        int i;
        for (i=0; i<20000; i++){}
        
    }
}