#include <msp430.h>

#include "keypad.h"

void keypad_init() {
    // initialize GPIO pins, maybe clock as well?

}

void keypad_update(int input[8]) {
    /*
        Intended behavior:
        * Log input
          - or clear if D
        * If last of 4, check against unlock code(s)
          - unlock if incorrect
          - clear log if not
        * once unlocked, input drives LED patterns
    */

}