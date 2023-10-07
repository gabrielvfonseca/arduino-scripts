# Light Sensor Control with Arduino

This Arduino project was developed by Gabriel on February 26, 2021. It utilizes an Arduino board, a light sensor, and an LED to control the brightness of the LED based on the ambient light levels measured by the sensor.

## Components Used

- Arduino board (compatible with LiquidCrystal library)
- Light sensor (connected to analog pin A0)
- LED (connected to digital pin 9)
- 16x2 LCD display (connected to pins 12, 11, 5, 4, 3, 2)

## Description

The Arduino program reads data from the light sensor and calculates the average light level over four readings. Depending on the average light level, it adjusts the brightness of the LED. Here's a breakdown of how it works:

- The light sensor is read four times with a delay of 100 milliseconds between readings.
- The readings are summed, and the average is calculated.
- Based on the average light level, the LED brightness is adjusted using PWM (Pulse Width Modulation).
- The program also displays the average light level on the LCD screen.

## Usage

1. Connect the components as described in the "Components Used" section.
2. Upload the Arduino code to your Arduino board.
3. Power on the circuit.
4. The LED brightness will vary based on the ambient light level.
5. The average light level is displayed on the LCD screen.

## License

This project is open-source and available under the [MIT License](LICENSE.md).

## Acknowledgments

- Thanks to the LiquidCrystal library for providing an easy way to interface with the LCD display.
- Inspiration and guidance from the Arduino community.

Feel free to modify and improve upon this project as needed. If you have any questions or suggestions, please don't hesitate to reach out to Gabriel.

Happy tinkering!
