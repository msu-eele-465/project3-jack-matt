
#include <msp430.h>

void init(void) {
  P6DIR |= BIT6; // configure LED2
  P6OUT &= ~BIT6;
  return;
}

void run(void) {
  P6OUT ^= BIT6;
  return;
}