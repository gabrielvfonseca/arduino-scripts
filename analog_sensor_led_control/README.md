# Arduino Analog Sensor Threshold Control

This Arduino sketch is designed to read analog sensor data from pin A0 and control an LED (connected to pin 9) based on a threshold value. If the sensor reading is below the specified threshold, the LED is turned on; otherwise, it is turned off. The sensor readings are also printed to the Serial Monitor for monitoring.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Analog sensor (connected to analog pin A0)
- LED (connected to digital pin 9)
- Jumper wires

## Circuit Connection

1. Connect the analog sensor (e.g., light sensor, temperature sensor, etc.) to analog pin A0 on the Arduino.
2. Connect the LED anode (longer leg) to digital pin 9 on the Arduino.
3. Connect the LED cathode (shorter leg) to the ground (GND) on the Arduino.
4. Ensure the sensor is powered and properly connected to the ground (GND) and power (5V) as required by the specific sensor.

## Code Explanation

- `limiteDisparo` is defined as 600, which is the threshold value for the sensor reading. If the sensor reading is below this threshold, the LED is turned on.
- `led` is defined as 9, which is the pin to which the LED is connected.
- `sensor` is defined as A0, which is the analog pin to which the sensor is connected.
- `sensorValue` is used to store the current analog sensor reading.

In the `setup` function:
- pinMode is set for `led` as OUTPUT to control the LED.
- pinMode is set for `sensor` as INPUT to read the sensor.
- Serial communication is initialized with a baud rate of 9600 to enable communication with the Serial Monitor.

In the `loop` function:
- The analog sensor reading from pin A0 is obtained using `analogRead(sensor)` and stored in `sensorValue`.
- If the sensor reading (`sensorValue`) is below the specified threshold (`limiteDisparo`), the LED is turned on using `digitalWrite(led, HIGH)`; otherwise, it's turned off with `digitalWrite(led, LOW)`.
- The sensor reading (`sensorValue`) is printed to the Serial Monitor for monitoring.
- A delay of 130 milliseconds is added between each reading to control the rate at which data is displayed in the Serial Monitor.

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly, with the analog sensor connected to pin A0 and the LED connected to pin 9.
3. Open the Serial Monitor in the Arduino IDE (Tools -> Serial Monitor) to view the analog sensor readings and LED control.
4. Observe the LED turning on when the sensor reading falls below the specified threshold.

This example demonstrates how to read analog sensor data and control an LED based on a threshold using an Arduino.

## License

This code is provided without any specific license. You are free to use, modify, and distribute it for both personal and commercial use at your own discretion.
