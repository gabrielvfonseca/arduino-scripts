# Arduino Button and LED Example

This is a simple Arduino sketch that demonstrates how to control an LED using a push button. When the button is pressed, the LED turns on, and when the button is released, the LED turns off.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Push button
- LED
- 220-ohm resistor (for LED current limiting)
- Jumper wires

## Circuit Connection

1. Connect one leg of the push button to digital pin 2 (buttonPin).
2. Connect the other leg of the push button to the ground (GND).
3. Connect one leg of the LED to digital pin 8 (ledPin).
4. Connect the other leg of the LED to a 220-ohm resistor.
5. Connect the other end of the resistor to the ground (GND).

## Code Explanation

- `buttonPin` is defined as 2, which is the pin to which the push button is connected.
- `ledPin` is defined as 8, which is the pin to which the LED is connected.
- `buttonState` is used to store the state of the button (pressed or released).

In the `setup` function:
- Serial communication is initialized for debugging purposes.
- The pinMode for `ledPin` is set as OUTPUT to control the LED.
- The pinMode for `buttonPin` is set as INPUT to read the button's state.

In the `loop` function:
- `buttonState` is updated with the current state of the button using `digitalRead`.
- If the button is pressed (buttonState is true), the LED is turned on, and a message is sent over serial indicating that it's on.
- If the button is released (buttonState is false), the LED is turned off, and a message is sent over serial indicating that it's off.
- A delay of 1 second is added between each cycle to avoid rapid state changes.

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly.
3. Open the Serial Monitor to view the status of the LED (on or off) as you press and release the button.

Feel free to modify the code and experiment with different components to create more complex projects or add additional features.

## License

This code is provided under the MIT License. You are free to use, modify, and distribute it for both personal and commercial use. See the [LICENSE](LICENSE) file for more details.
