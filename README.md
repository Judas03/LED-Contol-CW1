Introduction 

The objective of this project is to control a set of LEDs in a traffic light style using the NUCLEO-F401RE microcontroller. The project also includes an additional component, a 7-segment display, as my extra work. The microcontroller will read the state of a push-button switch and operate the LEDs accordingly. The 7-segment display will be utilized to show a countdown during the red LED phase. Additionally, the project will implement a feature where pressing the button twice will switch off the green LED and activate a blinking amber LED in an infinite loop.

Hardware Setup

The hardware setup for this project includes the following components:
●	NUCLEO-F401RE microcontroller
●	Breadboard
●	Red, green, and yellow LEDs
●	Push-button switch
●	Resistors for current limiting
The LEDs are connected to the breadboard with appropriate current-limiting resistors to prevent excessive current flow. 
1.Connect the microcontroller to the breadboard:
●	Connect the 3.3V pin (VCC) of the microcontroller to the positive rail of the breadboard.
●	Connect the GND pin of the microcontroller to the ground rail of the breadboard.
2.Connect the LEDs to the microcontroller:
	Connect the anode (longer leg) of the red LED to a digital output pin (e.g., PC_10) of the microcontroller.
	Connect the cathode (shorter leg) of the red LED to one end of a current-limiting resistor (typically 220-470 ohms).
	Connect the other end of the resistor to the ground rail of the breadboard.
	Repeat the above steps for the green LED (connect to PC_3) and the yellow LED (connect to PC_12).
3.Connect the 7-segment display to the microcontroller:
●	Connect the segment a of the 7-segment display to a digital output pin (e.g., PC_8) of the microcontroller.
●	Connect segment b to PC_6, segment c to PC_5, segment d to PA_12, segment e to PA_11, segment f to PC_0, segment g to PC_4, and the decimal point (dp) to PC_9.
●	Connect the common cathode or anode of the 7-segment display to the ground rail or the positive rail of the breadboard, respectively.


