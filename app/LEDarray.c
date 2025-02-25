#include "LEDarray.h"
#include <msp430.h>

// Pattern timing control
static float base_transition_period = 1.0;  // Default 1.0s
static unsigned int pattern_step = 0;
static led_pattern_t current_pattern = PATTERN_NONE;
static bool pattern_active = false;

// Pattern definitions
static const unsigned char STATIC_PATTERN = 0xAA;  // 10101010

static const unsigned char TOGGLE_PATTERN[2] = {
    0xAA,   // 10101010
    0x55    // 01010101
};

static const unsigned char IN_OUT_PATTERN[6] = {
    0x18,   // 00011000
    0x24,   // 00100100
    0x42,   // 01000010
    0x81,   // 10000001
    0x42,   // 01000010
    0x24    // 00100100
};

// Timer initialization for pattern updates
static void init_timer(void) {
    // Using Timer A1 for pattern updates
    TA1CCR0 = 50000;     // Initial period for 1Hz with 1MHz SMCLK
    TA1CCTL0 = CCIE;     // Enable interrupt
    TA1CTL = TASSEL__SMCLK | MC__UP | TACLR;
}

void ledarray_init(void) {
    // Configure LED pins as outputs
    P5DIR |= LED_PINS;
    P5OUT &= ~LED_PINS;  // All LEDs off initially
    
    init_timer();
}

void ledarray_all_off(void) {
    P5OUT &= ~LED_PINS;
    pattern_active = false;
    current_pattern = PATTERN_NONE;
}

void ledarray_select_pattern(led_pattern_t pattern) {
    if (pattern == current_pattern) {
        // Restart pattern
        pattern_step = 0;
    } else {
        current_pattern = pattern;
        pattern_step = 0;
    }
    pattern_active = true;
}

void ledarray_set_transition_period(float period) {
    base_transition_period = period;
    
    // Update timer period
    unsigned int timer_counts = (unsigned int)(period * 1000000); // Assuming 1MHz SMCLK
    TA1CCR0 = timer_counts;
}

float ledarray_get_transition_period(void) {
    return base_transition_period;
}

void ledarray_decrease_period(void) {
    if (base_transition_period > 0.25) {
        ledarray_set_transition_period(base_transition_period - 0.25);
    }
}

void ledarray_increase_period(void) {
    ledarray_set_transition_period(base_transition_period + 0.25);
}

void ledarray_update(void) {
    if (!pattern_active) return;
    
    switch (current_pattern) {
        case PATTERN_0_STATIC:
            P5OUT = (P5OUT & ~LED_PINS) | STATIC_PATTERN;
            break;
            
        case PATTERN_1_TOGGLE:
            P5OUT = (P5OUT & ~LED_PINS) | TOGGLE_PATTERN[pattern_step];
            pattern_step = (pattern_step + 1) % 2;
            break;
            
        case PATTERN_2_UP_COUNT:
            P5OUT = (P5OUT & ~LED_PINS) | pattern_step;
            pattern_step = (pattern_step + 1) % 256;
            break;
            
        case PATTERN_3_IN_OUT:
            P5OUT = (P5OUT & ~LED_PINS) | IN_OUT_PATTERN[pattern_step];
            pattern_step = (pattern_step + 1) % 6;
            break;
            
        default:
            P5OUT &= ~LED_PINS;
            break;
    }
}

// Timer A1 interrupt handler
#pragma vector = TIMER1_A0_VECTOR
__interrupt void Timer1_A0_ISR(void) {
    // Update LED pattern
    ledarray_update();
}