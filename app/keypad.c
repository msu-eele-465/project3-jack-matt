#include "keypad.h"
#include <msp430.h>

// Keypad matrix mapping
static const char keymap[4][4] = {{'1', '2', '3', 'A'},
                                  {'4', '5', '6', 'B'},
                                  {'7', '8', '9', 'C'},
                                  {'*', '0', '#', 'D'}};

// Unlock code (can be changed)
static const char unlock_code[4] = {'1', '2', '3', '4'};
static char entered_code[4];
static unsigned char code_index = 0;
static bool is_unlocked = false;

void keypad_init(void) {
  // Configure LED pin as output
  P1DIR |= LED_PIN;
  LED_PORT &= ~LED_PIN; // LED off initially

  // Configure row pins as outputs
  P4DIR |= ROW_PINS;
  P4OUT &= ~ROW_PINS; // Set rows low initially

  // Configure column pins as inputs with pull-up resistors
  P6DIR &= ~COL_PINS;
  P6REN |= COL_PINS; // Enable pull-up/down resistors
  P6OUT |= COL_PINS; // Set pull-up
}

char keypad_scan(void) {
  char key = 0;
  unsigned char row, col;

  // Scan each row
  for (row = 0; row < 4; row++) {
    // Set current row high, others low
    ROW_PORT = (ROW1_PIN << row);

    // Small delay for signal to stabilize
    __delay_cycles(1000);

    // Read columns
    unsigned char cols = (~COL_IN) & 0x0F; // Read and invert (buttons pull low)

    if (cols) {               // If any column is low (button pressed)
      LED_PORT |= LED_PIN;    // Turn on LED when key pressed
      __delay_cycles(100000); // Delay for visibility
      LED_PORT &= ~LED_PIN;   // Turn off LED

      for (col = 0; col < 4; col++) {
        if (cols & (1 << col)) {
          key = keymap[row][col];
          break;
        }
      }
      break;
    }
  }

  // Return to default state
  ROW_PORT &= ~ROW_PINS;

  // If a key was pressed, process it for unlock code
  if (key && !is_unlocked) {
    entered_code[code_index] = key;
    code_index = (code_index + 1) % 4;

    // Check code when 4 digits entered
    if (code_index == 0) {
      keypad_check_unlock();
    }
  }

  return key;
}

bool keypad_check_unlock(void) {
  unsigned char i;
  bool match = true;

  for (i = 0; i < 4; i++) {
    if (entered_code[i] != unlock_code[i]) {
      match = false;
      break;
    }
  }

  is_unlocked = match;
  return match;
}

bool keypad_is_unlocked(void) { return is_unlocked; }