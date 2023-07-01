#include "mbed.h"

// Define the LED pins connected to the breadboard
DigitalOut redLED(PC_10);
DigitalOut yellowLED(PC_12);
DigitalOut greenLED(PC_3);

// Define the button pin
DigitalIn button(PC_13);

// Define the LED pin on the microcontroller
DigitalOut ld2(LED1);

// Define 7-segment pins
DigitalOut a(PC_8);
DigitalOut b(PC_6);
DigitalOut c(PC_5);
DigitalOut d(PA_12);
DigitalOut e(PA_11);
DigitalOut f(PC_0);
DigitalOut g(PC_4);
DigitalOut dp(PC_9);

// Function to display a number on the 7-segment display
void displayNumber(int num)
{
    switch (num) {
        case 0:
            a = b = c = d = e = f = 1;
            g = 0;
            break;
        case 1:
            b = c = 1;
            a = d = e = f = g = 0;
            break;
        case 2:
            a = b = g = e = d = 1;
            c = f = 0;
            break;
        case 3:
            a = b = c = d = g = 1;
            e = f = 0;
            break;
        case 4:
            b = c = f = g = 1;
            a = d = e = 0;
            break;
        case 5:
            a = c = d = f = g = 1;
            b = e = 0;
            break;
        case 6:
            a = c = d = e = f = g = 1;
            b = 0;
            break;
        case 7:
            a = b = c = 1;
            d = e = f = g = 0;
            break;
        case 8:
            a = b = c = d = e = f = g = 1;
            break;
        case 9:
            a = b = c = d = f = g = 1;
            e = 0;
            break;
        default:
            a = b = c = d = e = f = g = 0;
            break;
    }
}

int main()
{
    bool buttonPressed = false;
    bool greenLedOn = true;
    greenLED = 1;
    int buttonPressCount = 0;

    // Check the initial state of the button
    bool prevButtonState = button;
    
    while (1) {
        bool currentButtonState = button;

        if (currentButtonState && !prevButtonState && !buttonPressed) {
            buttonPressed = true;
            buttonPressCount++;

            if (buttonPressCount == 2) {
                greenLED = 0;   // Turn off green LED
                yellowLED = 1;  // Turn on yellow LED

                // Blink the amber LED in an interval of 1 second
                while (1) {
                    yellowLED = !yellowLED; // Toggle the amber LED state
                    wait_us(1000000);  // Wait for 1 second (1000000 microseconds)
                }
            }
            else {
                greenLED = 1;   // Turn on green LED
                wait_us(3000000);  // Wait for 3 seconds (3000000 microseconds)

                greenLED = 0;   // Turn off green LED
                yellowLED = 1;  // Turn on yellow LED
                wait_us(3000000);  // Wait for 3 seconds (3000000 microseconds)

                yellowLED = 0;  // Turn off yellow LED
                ld2 = 1;
                redLED = 1;    // Turn on red LED

                // Count down from 3 to 1 on the 7-segment display
                for (int i = 3; i >= 1; i--) {
                    displayNumber(i);
                    wait_us(1000000);  // Wait for 1 second (1000000 microseconds)
                }

                redLED = 0;     // Turn off red LED
                ld2 = 0;
                greenLED = 1;

                // Reset the 7-segment display to display nothing
                displayNumber(-1);
            }
        }
        else if (!currentButtonState) {
            buttonPressed = false;
        }
        
        prevButtonState = currentButtonState;
    }
}
