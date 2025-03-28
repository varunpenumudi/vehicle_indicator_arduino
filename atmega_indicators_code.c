#include <avr/io.h>
#include <util/delay.h>

// PINS
#define LIN_PIN PB4
#define LOUT_PIN PB5

#define RIN_PIN PB1
#define ROUT_PIN PB2


unsigned int count = 0;


int main() {

    DDRB = (1 << LOUT_PIN) | (1 << ROUT_PIN);   // PORTB IO PINS
    PORTB = 0;
    unsigned int left=0, right=0;


    while (1) {

        // Either LEFT or RIGHT Pressed
        if (count == 10) {
            count = 0;

            // BOTH LEFT and RIGHT Pressed
            if ((PINB & ((1 << RIN_PIN) | (1 << LIN_PIN))) == ((1 << RIN_PIN) | (1 << LIN_PIN))) {
                if (left == 1 && right == 1) {
                    left = 0, right = 0;
                }
                else {
                    left = 1, right = 1;
                }
            }
            // LEFT Pressed
            else if (PINB & (1 << LIN_PIN)) {
                if (left == 0) {
                    right = 0;  left = 1;
                }
                else {
                    right = 0; left = 0;  
                }
            }
            // RIGHT Pressed
            else if (PINB & (1 << RIN_PIN)) {
                if (right == 0) {
                    left = 0; right = 1;
                }
                else {
                    left = 0; right = 0;
                }
            }

            PORTB = 0;
        }
        else if (PINB & ((1 << RIN_PIN) | (1 << LIN_PIN))) {
            count ++;
        }
        else {
            count = 0;
        }


        // Flicker or not the LED's
        if (left && right) {
            PORTB ^= (1 << LOUT_PIN) | (1 << ROUT_PIN);
        }
        else if (left) {
            PORTB ^= (1 << LOUT_PIN);
        }
        else if (right) {
            PORTB ^= (1 << ROUT_PIN);
        }
        else {
            PORTB = 0;
        }

        // wait 100ms
        _delay_ms(100);
    }

    return 0;
}