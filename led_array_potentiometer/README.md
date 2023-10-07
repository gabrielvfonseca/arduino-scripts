# Arduino LED Array with Potentiometer Control

This Arduino sketch is designed to control an array of LEDs using a potentiometer (analog input). The brightness of the LEDs is adjusted based on the potentiometer reading. The code sequentially lights up each LED in the array with a brightness level determined by the potentiometer value.

## Components Used

- Arduino board (e.g., Arduino Uno)
- LEDs (connected to pins 2, 4, 7, 8, and 12)
- Potentiometer (connected to analog pin A0)
- Resistors (for current limiting of LEDs)
- Jumper wires

## Circuit Connection

1. Connect each LED with a current-limiting resistor to digital pins 2, 4, 7, 8, and 12.
2. Connect the common (ground) leg of all LEDs to the ground (GND) of the Arduino.
3. Connect one leg of the potentiometer to 5V on the Arduino.
4. Connect the other leg of the potentiometer to the ground (GND) on the Arduino.
5. Connect the center pin of the potentiometer to analog pin A0 on the Arduino.

## Code Explanation

- `ledPin` is an array containing the digital pins (2, 4, 7, 8, 12) to which the LEDs are connected.
- `potPin` is defined as A0, which is the analog pin to which the potentiometer is connected.
- `value` is used to store the analog reading from the potentiometer.
- `i` is used as a loop variable to iterate through the LEDs.

In the `setup` function:
- A `for` loop is used to set each pin in the `ledPin` array as OUTPUT to control the LEDs.
- pinMode is set for `potPin` as INPUT to read the potentiometer.
- Serial communication is initialized for debugging purposes.

In the `loop` function:
- The analog reading from the potentiometer is stored in the `value` variable.
- The current value of the potentiometer is printed to the Serial Monitor for monitoring.
- A `for` loop is used to iterate through each LED in the array:
  - The LED is briefly turned on and then off with a delay determined by the `value` (brightness level).

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly.
3. Open the Serial Monitor to view the potentiometer readings.
4. Observe how the brightness of the LEDs changes based on the potentiometer position.

Feel free to modify the code and experiment with different LED patterns or add more features to your LED array project.

## License

This code is provided without any specific license. You are free to use, modify, and distribute it for both personal and commercial use at your own discretion.
