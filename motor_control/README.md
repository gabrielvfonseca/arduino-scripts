# Motor Control with Arduino

This Arduino sketch is designed to control a motor using a button and an analog input to adjust the motor speed. It also includes a status LED to indicate when the motor is running. This code was developed by Gabriel on 16/04/2021.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Motor driver and motor
- Push button
- Potentiometer (or any other variable resistance sensor)
- LED
- Resistors and wires

## Wiring Instructions

1. Connect the motor driver to the Arduino board.
2. Connect the push button to the Arduino board.
3. Connect the potentiometer to the Arduino board.
4. Connect the LED to the Arduino board.

Make sure to review the pin connections in the code and match them with your physical setup.

## Code Explanation

- `motorPin` (Pin 10): This pin is used to control the motor.
- `analogPin` (A0): This pin reads the analog value from the potentiometer.
- `LED` (Pin 12): This pin is used to indicate the motor's status.
- `speed` and `output` are variables used to store the motor speed and output value.
- `setup()` function initializes the pins and sets up interrupt handlers.
- `loop()` function is empty because the code relies on interrupts to handle button presses.
- `buttonPressedON()` function is called when the button is pressed and turns on the LED and the motor at a speed determined by the potentiometer.
- `buttonPressedOFF()` function is called when the button is released and turns off the LED and the motor.

## Usage

1. Upload the code to your Arduino board.
2. Ensure that your wiring is correct.
3. Open the Arduino Serial Monitor (baud rate: 3600).
4. Press and release the button to turn the motor on and off.
5. Observe the motor speed values displayed in the Serial Monitor.

## License

This code is provided as-is and can be used and modified freely. Please attribute the original author, Gabriel, if you use or share this code.

## Acknowledgments

- Thanks to Gabriel for developing this Arduino sketch.
