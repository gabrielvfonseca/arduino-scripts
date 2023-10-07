# Arduino PIR Motion Sensor and Relay Control

This Arduino sketch is designed to control a relay based on inputs from a Passive Infrared (PIR) motion sensor and an analog sensor. When motion is detected by the PIR sensor or when the analog sensor reading is high, the relay is turned on. Otherwise, the relay is turned off.

## Components Used

- Arduino board (e.g., Arduino Uno)
- PIR motion sensor
- Relay module
- Analog sensor (e.g., light sensor, temperature sensor, etc.)
- Jumper wires

## Circuit Connection

1. Connect the output pin of the PIR motion sensor to digital pin 5 (pinPIR).
2. Connect the control pin of the relay module to digital pin 3 (pinRelay).
3. Connect the analog sensor to analog pin A0 (pinAnalog).
4. Connect the necessary power and ground connections for each component.

## Code Explanation

- `pinPI
