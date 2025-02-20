#ifndef KEYPADH
#define KEYPADH

#include <msp430.h>
#include <stdbool.h>

// Status LED pin definition
#define LED_PIN BIT0      // P1.0
#define LED_PORT P1OUT

// RGB LED pins (using Timer_B PWM)
#define RGB_RED_PIN   BIT7    // P1.7 - TB1.1
#define RGB_GREEN_PIN BIT6    // P1.6 - TB1.2
#define RGB_BLUE_PIN  BIT5    // P1.5 - TB1.3

// Keypad pin definitions 
#define ROW1_PIN BIT4     // P4.4
#define ROW2_PIN BIT5     // P4.5
#define ROW3_PIN BIT6     // P4.6
#define ROW4_PIN BIT7     // P4.7
#define ROW_PINS (ROW1_PIN | ROW2_PIN | ROW3_PIN | ROW4_PIN)
#define ROW_PORT P4OUT

#define COL1_PIN BIT0     // P6.0
#define COL2_PIN BIT1     // P6.1
#define COL3_PIN BIT2     // P6.2
#define COL4_PIN BIT3     // P6.3
#define COL_PINS (COL1_PIN | COL2_PIN | COL3_PIN | COL4_PIN)
#define COL_PORT P6OUT
#define COL_IN P6IN

// Function prototypes
void keypad_init(void);
char keypad_scan(void);
bool keypad_check_unlock(void);
bool keypad_is_unlocked(void);
void rgb_set_color(unsigned char red, unsigned char green, unsigned char blue);

// System states
typedef enum {
    SYSTEM_LOCKED,
    SYSTEM_UNLOCKING,
    SYSTEM_UNLOCKED
} system_state_t;

#endif /* KEYPADH */