# Arduino Web Server with Environmental Monitoring

## Overview

This Arduino project is designed to create a web server using a Wemos D1 board for environmental monitoring. It includes features for monitoring temperature and smoke levels and responding to certain conditions with actions like activating LEDs and a buzzer. The project connects to a MySQL database to store sensor data and provides a web interface for user interaction.

## Table of Contents

- [Requirements](#requirements)
- [Setup](#setup)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Requirements

Before you begin, make sure you have the following components and software installed:

- Wemos D1 board (or similar ESP8266-based board)
- Temperature sensor (e.g., LM35)
- Smoke sensor (e.g., MQ2)
- LED(s)
- Buzzer
- LCD Display (16x2)
- Arduino IDE with ESP8266 support
- Wi-Fi network with SSID and password
- MySQL database server
- PHP web server (for web interface)

## Setup

1. **Hardware Connections**: Connect the components to your Wemos D1 board following the pin assignments specified in the code.

2. **Arduino IDE Setup**:
   - Install the Arduino IDE if you haven't already.
   - Install the ESP8266 board package through the Arduino Boards Manager.
   - Open the Arduino IDE and select the Wemos D1 board from the Tools > Board menu.
   - Install any required libraries by going to Sketch > Include Library > Manage Libraries and searching for the libraries used in the code (e.g., LiquidCrystal, ESP8266WiFi, MySQL Connector, etc.).

3. **Database Configuration**:
   - Set up a MySQL database server and create a database for storing sensor data.
   - Modify the `db_user`, `db_password`, `server_addr`, and SQL query (`INSERT_SQL`) in the Arduino code to match your database credentials and schema.

4. **Wi-Fi Configuration**:
   - Replace `ssid` and `password` in the code with your Wi-Fi network credentials.

5. **Web Interface**:
   - Set up a PHP web server for hosting the web interface.
   - Implement the missing parts of the web interface (e.g., HTML, PHP scripts) for user interaction and instructions. Link the Arduino code to these scripts for data exchange.

6. **Upload Code**: Compile and upload the Arduino code to your Wemos D1 board.

## Project Structure

The project's Arduino code is organized into functions and sections, each serving a specific purpose. Here are some key components:

- **Initialization**: Initialize pins, components, and establish connections (Wi-Fi and database).
- **Main Loop**: Continuously monitor sensor data, handle user instructions from the web interface, and trigger alarms when necessary.
- **Functions**: Reusable functions for controlling LEDs, making sounds with the buzzer, reading sensor data, and more.
- **Comments**: Detailed comments throughout the code explain the purpose of each function and section.

## Usage

1. Power on your Wemos D1 board, ensuring it's connected to the Wi-Fi network.

2. Access the web interface hosted on your PHP web server to interact with the project. Implement the web interface to provide user instructions and monitor sensor data.

3. Observe the environmental data on the web interface, and the system will respond by activating LEDs and a buzzer when predefined conditions are met.

4. Sensor data is stored in the MySQL database for analysis and historical tracking.

## Contributing

Contributions to this project are welcome. You can contribute by improving the code, enhancing the documentation, or implementing additional features.

## License

This project is licensed under the [MIT License](LICENSE).
