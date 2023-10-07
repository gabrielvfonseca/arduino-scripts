# Arduino Sequential LED Blinking Example

This Arduino sketch demonstrates how to sequentially blink three LEDs connected to different pins on the Arduino board. Each LED is turned on for 2 seconds and then turned off before moving to the next LED in the sequence. This cycle continues indefinitely.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Three LEDs (connected to pins 13, 12, and 8)
- Jumper wires

## Circuit Connection

1. Connect the first LED's longer leg (anode) to digital pin 13 (LED1).
2. Connect the second LED's longer leg (anode) to digital pin 12 (LED2).
3. Connect the third LED's longer leg (anode) to digital pin 8 (LED3).
4. Connect the shorter leg (cathode) of all three LEDs to the ground (GND).

## Code Explanation

- `LED1`, `LED2`, and `LED3` are defined as the pin numbers to which the three LEDs are connected.

In the `setup` function:
- pinMode is set for each LED pin as OUTPUT to control the LEDs.

In the `loop` function:
- Three separate functions (`start_LED1`, `start_LED2`, and `start_LED3`) are called sequentially to blink each LED.
- Each LED is turned on by setting its corresponding pin to HIGH.
- A delay of 2 seconds is added to keep the LED on for 2 seconds.
- The LED is then turned off by setting its pin to LOW.
- Another delay of 2 seconds is added to keep the LED off for 2 seconds.
- This sequence of turning on and off is repeated for each LED in the order specified.

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly.
3. Observe the LEDs as they blink sequentially, one after the other, with a 2-second interval for each LED.

This example demonstrates how to control multiple LEDs in a sequential pattern, allowing for creative lighting effects in your projects.

## License

This code is provided without any specific license. You are free to use, modify, and distribute it for both personal and commercial use at your own discretion.
