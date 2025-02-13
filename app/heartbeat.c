
#include <msp430.h>

int i = 0;
int main(void) {
  WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

  int SW1;
  int SW2;
  P1DIR |= BIT0; // configure LED1
  P1OUT &= ~BIT0;
  P6DIR |= BIT6; // configure LED2
  P6OUT &= ~BIT6;

  P4DIR &= ~BIT1; // set P4.1 direction = in
  P4REN |= BIT1;  // enable PU/PD Resistor
  P4OUT |= BIT1;  // set PU resistor
  P4IES |= BIT1;  // set IRQ H-L

  P2DIR &= ~BIT3; // set P2.3 direction = in
  P2REN |= BIT3;  // enable PU/PD Resistor
  P2OUT |= BIT3;  // set PU resistor
  P2IES |= BIT3;  // set IRQ H-L

  PM5CTL0 &= ~LOCKLPM5; // GPIO

  // IRQ

  P4IFG &= ~BIT1; // clear p4.1 IRQ flag
  P4IE |= BIT1;   // enable P4.1 IRQ
  P2IFG &= ~BIT3; // clear p2.3 IRQ flag
  P2IE |= BIT3;   // enable P2.3 IRQ

  __enable_interrupt(); // enable maskable IRQs

  while (1) {
    /**
    SW1 = P4IN;
    SW1 &= BIT1; //clear bits in SW1 except 4.1
    SW2 = P2IN;
    SW2 &= BIT3; //clear bits in SW2 except 2.3

    if (SW2 == 0){
        if ((i > 1)) {
            i-=2;
        }
        delay();

    }
    if (SW1 == 0){
        if (!(i >= 3)) {
                i++;
        }
        delay();
    }t
    */

    // DEMO 2
    switch (i) {
    case 0: // 00
      P1OUT &= ~BIT0;
      P6OUT &= ~BIT6;
      break;
    case 1: // 01
      P1OUT &= ~BIT0;
      P6OUT |= BIT6;
      break;
    case 2: // 10
      P1OUT |= BIT0;
      P6OUT &= ~BIT6;
      break;
    case 3: // 11
      P1OUT |= BIT0;
      P6OUT |= BIT6;
      break;
    }
  }

  return 0;
}
void delay() {
  int k = 0;
  for (k = 0; k < 0xFFFF; k++) {
  }
  return;
}

//------------Interrupt Service Routines--------------
#pragma vector = PORT4_VECTOR

__interrupt void ISR_Port4_S1(void) {
  if (!(i >= 3)) {
    i++;
  }
  P4IFG &= ~BIT1; // clear flag
}

#pragma vector = PORT2_VECTOR

__interrupt void ISR_Port2_S2(void) {
  if ((i > 1)) {
    i -= 2;
  }
  P2IFG &= ~BIT3; // clear flag
}
