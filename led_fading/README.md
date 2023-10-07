# LED Fading with Arduino

This Arduino sketch is designed to control the brightness of an LED using pulse-width modulation (PWM). The LED will gradually fade in and out in a loop. This code was developed by Gabriel on 17/02/2021.

## Components Used

- Arduino board (e.g., Arduino Uno)
- LED
- Resistor (if necessary)
- Wires

## Wiring Instructions

1. Connect the anode (longer lead) of the LED to a current-limiting resistor.
2. Connect the other end of the resistor to digital pin 9 on the Arduino board.
3. Connect the cathode (shorter lead) of the LED to the Arduino's ground (GND) pin.

Ensure that your LED is correctly oriented (anode connected to the resistor, cathode connected to GND).

## Code Explanation

- `brightness` is a variable that represents the LED's brightness level.
- `pinLED` (Pin 9): This pin is used to control the LED.
- `setup()` function sets the `pinLED` as an output.
- `loop()` function continuously fades the LED in and out using PWM. It incrementally increases and decreases the `brightness` value.

## Usage

1. Upload the code to your Arduino board.
2. Ensure that your wiring is correct
