# Light Sensor with LED Control

This program, developed by Gabriel on 26/02/2021, controls the intensity of an LED based on ambient light levels. The program uses a light sensor and a 16x2 LCD display to show the average readings from the sensor while adjusting the LED's brightness according to predefined light level ranges.

## Required Components

- Arduino (or compatible board)
- Light Sensor (LDR - Light Dependent Resistor)
- 16x2 LCD Display
- LED
- 220-ohm Resistor
- Jumper wires and cables

## Used Libraries

**LiquidCrystal.h**: This library is used to control the LCD display.
Pin Configuration

**LED**: Connected to Arduino pin 9.
**Light Sensor**: Connected to analog input A0 of the Arduino.
**LCD Display**: Connected to Arduino pins 2, 3, 4, 5, 11, and 12.

## Operation

The program performs the following operations:

Initializes the LED, LCD display, and serial monitor.
In the luz() function, it reads the light sensor value four times with 500 milliseconds intervals, calculates the average of these values, and displays the average on the LCD display.
In the main loop, based on the average light level (media), it adjusts the LED's intensity according to predefined light level ranges. The light level ranges and corresponding LED intensities are defined in the code.
The program also sends messages to the serial monitor.