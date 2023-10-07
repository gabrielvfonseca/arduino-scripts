# Arduino RGB LED Control with Button

This Arduino sketch demonstrates how to control an RGB LED with a button. When the button is pressed, the RGB LED cycles through different colors (red, green, and blue) with a 1-second delay between each color. The RGB LED's color is controlled using PWM (Pulse Width Modulation) on individual pins for red, green, and blue.

## Components Used

- Arduino board (e.g., Arduino Uno)
- RGB LED common cathode (with separate pins for red, green, and blue)
- Push button
- Resistors (for current limiting)
- Jumper wires

## Circuit Connection

1. Connect the common cathode of the RGB LED to the ground (GND) on the Arduino.
2. Connect the red pin of the RGB LED to pin 13 on the Arduino (red_light_pin).
3. Connect the green pin of the RGB LED to pin 12 on the Arduino (green_light_pin).
4. Connect the blue pin of the RGB LED to pin 7 on the Arduino (blue_light_pin).
5. Connect one leg of the push button to digital pin 2 on the Arduino.
6. Connect the other leg of the push button to the ground (GND) on the Arduino.

## Code Explanation

- `red_light_pin`, `green_light_pin`, and `blue_light_pin` are defined as the pins to which the red, green, and blue components of the RGB LED are connected, respectively.
- pinMode is set for each LED pin as OUTPUT to control the RGB LED.
- pinMode is set for pin 2 as INPUT to read the button state.

In the `loop` function:
- The button state is checked using `digitalRead(pin 2)`. If the button is pressed (HIGH), the `start` function is called.

The `start` function:
- Cycles the RGB LED through different colors by setting different PWM values for the red, green, and blue components.
- It starts with red (255, 0, 0), then green (0, 255, 0), and finally blue (0, 0, 255).
- Each color is displayed for 1 second (1000 milliseconds) using `delay`.

The `RGB_color` function:
- Sets the PWM values for each color component based on the provided arguments (`red_light_value`, `green_light_value`, `blue_light_value`).

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly.
3. Press the button connected to pin 2 to cycle the RGB LED through different colors.

This example demonstrates how to control an RGB LED using PWM and a button press, allowing you to create dynamic lighting effects in your projects.

## License

This code is provided without any specific license. You are free to use, modify, and distribute it for both personal and commercial use at your own discretion.
