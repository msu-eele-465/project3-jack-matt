#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <msp430.h>
#include <stdbool.h>

// LED pin definition
#define LED_PIN BIT0 // P1.1
#define LED_PORT P1OUT

// Keypad pin definitions
#define ROW1_PIN BIT4 // P4.4
#define ROW2_PIN BIT5 // P4.5
#define ROW3_PIN BIT6 // P4.6
#define ROW4_PIN BIT7 // P4.7
#define ROW_PINS (ROW1_PIN | ROW2_PIN | ROW3_PIN | ROW4_PIN)
#define ROW_PORT P4OUT

#define COL1_PIN BIT0 // P6.0
#define COL2_PIN BIT1 // P6.1
#define COL3_PIN BIT2 // P6.2
#define COL4_PIN BIT3 // P6.3
#define COL_PINS (COL1_PIN | COL2_PIN | COL3_PIN | COL4_PIN)
#define COL_PORT P6OUT
#define COL_IN P6IN

// Function prototypes
void keypad_init(void);
char keypad_scan(void);
bool keypad_check_unlock(void);
bool keypad_is_unlocked(void);

#endif /* KEYPAD_H_ */