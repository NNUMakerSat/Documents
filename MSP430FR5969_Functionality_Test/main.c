#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;

    int i;
	
    P1DIR |= BIT0;						// Set LED1 as an output
    P4DIR = 0xFF;						// Set LED2 as an output

    while (1) {
    	P1OUT |= BIT0;
    	for (i = 0; i < 10; ++i) {
    		P4OUT = 0xFF;
    		__delay_cycles(10000000);
    	}
    }
}
