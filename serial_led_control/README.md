# Arduino Serial LED Control

This Arduino sketch enables the control of two LEDs (LED1 on pin 9 and LED2 on pin 10) using characters received over Serial communication. You can send characters 'a' and 'b' to turn on LED1 and LED2, respectively, and characters 'c' and 'd' to turn off LED2.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Two LEDs (connected to pins 9 and 10)
- Jumper wires

## Circuit Connection

1. Connect LED1's anode (longer leg) to digital pin 9 on the Arduino.
2. Connect LED2's anode (longer leg) to digital pin 10 on the Arduino.
3. Connect the cathode (shorter leg) of both LEDs to the ground (GND) on the Arduino.

## Code Explanation

- `led1` and `led2` are defined as pins 9 and 10, respectively, to which the LEDs are connected.
- `var` is a character variable used to store the character received over Serial communication.

In the `setup` function:
- Serial communication is initialized with a baud rate of 9600 to enable communication with an external device (e.g., computer).
- pinMode is set for `led1` and `led2` as OUTPUT to control the LEDs.

In the `loop` function:
- The code checks if there is data available in the Serial buffer using `Serial.available()`.
- If data is available, it is read into the `var` variable using `Serial.read()`.
- A `switch` statement is used to check the value of `var` and take corresponding actions:
  - If 'a' is received, LED1 (pin 9) is turned on.
  - If 'b' is received, LED2 (pin 10) is turned on.
  - If 'c' or 'd' is received, LED2 (pin 10) is turned off.

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly, with LED1 connected to pin 9 and LED2 connected to pin 10.
3. Open the Serial Monitor in the Arduino IDE (Tools -> Serial Monitor).
4. Send the characters 'a' and 'b' to turn on LED1 and LED2, respectively.
5. Send the characters 'c' or 'd' to turn off LED2.

This example demonstrates how to control LEDs using Serial communication, allowing for remote control of your Arduino project.

## License

This code is provided without any specific license. You are free to use, modify, and distribute it for both personal and commercial use at your own discretion.
