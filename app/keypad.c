#include <msp430.h>

#include "keypad.h"

void keypad_init() {
    // initialize GPIO pins, maybe clock as well?

}

void keypad_update(int input[8]) {
    /*
        Intended behavior:
        * if locked, log
        * if unlocked
          - lock if input 'D' then return
          - set pattern then return
    */

}

void keypad_log_input(int input[8]) {
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

void keypad_set_pattern(int input[8]) {
    /*
        Intended behavior:
        * case 0 -> set pattern 0
        * case 1 -> set pattern 1
        * case 2 -> set pattern 2
        * etc.
    */

}