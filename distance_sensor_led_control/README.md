# Distance Sensor with Buzzer and LED Control

This Arduino sketch is designed to work with a distance sensor and provide feedback through a buzzer and LED. When the distance sensor detects an object at a certain distance or the light level crosses a threshold, the buzzer produces a sound and the LED is turned on.

## Features

- Utilizes an ultrasonic distance sensor to measure distances in both inches and centimeters.
- Reads data from a light sensor to determine ambient light levels.
- Produces a buzzer sound with varying frequency based on the light level.
- Controls an LED to indicate specific conditions.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Ultrasonic distance sensor (HC-SR04 or similar)
- Light sensor (analog or digital)
- Buzzer
- LED
- Appropriate resistors, wires, and power source

## Arduino Pin Configuration

- LED is connected to pin 8.
- Buzzer is connected to pin 9.
- Ultrasonic sensor is connected to trigger and echo pins (both set to 7 in the code).
- Light sensor is connected to analog pin A0.
- The distance sensor trigger and echo pins are set to 7 in the code.

## Installation and Setup

1. Make sure you have the Arduino IDE installed on your computer.
2. Connect the hardware components according to the provided pin configuration.
3. Open the Arduino IDE, create a new project, and paste the code from this repository.
4. Upload the code to your Arduino board.

## Usage

1. After uploading the code, open the serial monitor to view distance measurements in inches and centimeters, as well as light sensor readings.
2. The program will activate the buzzer and turn on the LED when one of the following conditions is met:
   - Light level exceeds 500 (adjust as needed).
   - Object is detected within 10 cm of the ultrasonic distance sensor.
3. The LED and buzzer will stay active for 1.5 seconds and then turn off.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Author

This code was developed by Gabriel on 23rd April 2021.