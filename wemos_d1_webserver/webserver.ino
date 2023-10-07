/*
 * Dev by Gabriel. 
 * WebServer project with Arduino.
 * More info on README.md file.
 * 30/05/2021
*/

#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

/* NETWORK */
const char* ssid = "Vodafone-6079D7";
const char* password = "3EPffu2jud";

/* DATABASE */
const char* db_user = "root";
const char* db_password = "";

/* PORTS */
const int LedPin = 12; // LED Pin
const int BuzzerPin = 10; // Buzzer Pin
const int analogPin = A0; // AnalogPin
const int reset = 13; // Pin for Reset

/* ANALOG DATA */
int analogData; // Value of the sensor

const int mq2Pin = 2;
const int lm35Pin = 3;

/* LCD DISPLAY */
const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* SENSORS PRECISELY */
// All values can change acording to the user dashboard!
int Precise_mq2 = 400; // Standard value (smoke)
int Precise_lm35 = 10; // Standard value (temperature º)

int howManyValues = 4; // Defauld, leight of the array

/* MYSQL */
IPAddress server_addr(192,168,1,1); // MySql database IP adress
char user[] = db_user; // MySql User login
char password[] = db_password; // MySql User password

char INSERT_SQL[] = "INSERT INTO arduino.sensorData (id, data_sensorLM35, data_sensorMQ2) VALUES ('%d', '%d', '%d')";
char query[128];

/* START OBJECTS */
WiFiClient client;
MySQL_Connection conn((Client *)&client); 

/* SERVER */
WiFiServer server(80);

void setup() {
  /* OUTPUT PORTS */
  pinMode(LedPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(analogPin, OUTPUT);
  pinMode(reset, OUTPUT);
  pinMode(mq2Pin, OUTPUT);
  pinMode(lm35Pin, OUTPUT);
  pinMode(btn, OUTPUT);

  // Starts Serial and LCD
  Serial.begin(115200);
  lcd.begin(16, 2);

  // Connect to the network
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("WiFi connected!");
  server.begin(); // Starts the server
  
  // Print the Local IP address on Serial
  Serial.print("Local IP: ");
  Serial.print(WiFi.localIP());
  Serial.print("/");

  // Connect to MySQL
  while (!conn.connect(server_addr, 3306, user, password)) {
    Serial.println("Can't connect to SQL");
    conn.close();
    delay(1000);
  }
  Serial.println("Connected to SQL DB successfully");
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.print("New client!");
  while(!client.available()){
    delay(1);
  }

  /*
   * INSTRUCTIONS:
   * 1º => Check if the server button was pressed and to inicialize the server ==> changeHotspot()
   * 2º => Check if there is any client, if it is true then ==> SendWebData()
   *    2.1º => Check if the is a client then wait for some return data ==> ReceiveWebData()
   *    2.2º => Waint to make changes and calibrate the sensors based on user return data, if it recieves, then update parameters, if it don't then move on.
   * 3º => Executes searchForAlarm() function.
  */

}

void changeLed(int pin, bool state) {
  /*
   * Pin = Pin for the Buzzer
   * State = Gets the LED status, HIGH or LOW (type=Boolean)
   * This function recieves the paramets for what to do with the LED and than return it's status back.
  */ 
  
  // Turn ON/OFF the LED and return back is status
  digitalWrite(pin, state);
  delay(100); // Sleep/Wait 100 miliseconds

  if (digitalRead(pin == HIGH)) {
    // If the LED is ON, return it
    return 1; // 1 = HIGH
  }
  else {
    return 0; // 0 = LOW
  }
}

void makeSound(int pin) {
  /*
   * Pin = Pin for the Buzzer
  */ 
  
  int sound = 0;
  
  for(sound = 700; sound < 800; sound++){
    tone(pin, sound);
    delay(15);
  }

  for(sound = 800; sound > 700; sound--){
    tone(pin, sound);
    delay(15);
  }
}

void smokeSensor(int precise) {
  /*
   * Precise = How much sensor data you want to average (more data = more precise & slower)
  */ 
  
  int smokeData[precise]; // Colects 4 output data to analyze
  int average = 0; // Average of the sensor

  for(int index = 0; index < sizeof(smokeData); index++) {
    smokeData[index] = (oneAnalogPin("MQ2")); // ANALOG Sensor MQ2 on PIN A0 
    delay(150); // Wait 150 miliseconds
  }

  for (int vendor = 0; vendor < sizeof(smokeData); vendor++) {
    // Averge of all data combined
    average += smokeData[vendor];
  }
  average /= sizeof(smokeData); // Divided by the leight of the array (average)
  
  Serial.Println(average); // Print the average of the Sensor
  return average; // Return back the Sensor average
}

void tempSensor(int precise) {
  /*
   * Precise = How much precise will be the sensor
   * This function is monitoring the temperature get it by the LM35 sensor.
  */

  int reading; // Variable to read
  int tempData[precise]; // Colects 4 output data to analyze
  int average = 0; // Average of the sensor

  for(int index = 0; index < sizeof(tempData); index++) {
    reading = (oneAnalogPin("LM35")); // ANALOG Sensor LM35 on PIN A0 
    delay(150); // Wait 150 miliseconds

    float reading *= (5000 / 1024.0); // Convert the reading into voltage
    float tempData[index] = reading / 10;  // Convert the voltage into the temperature in degree
    delay(150); // Wait 150 miliseconds
  }

  for (int vendor = 0; vendor < sizeof(tempData); vendor++) {
    // Averge of all data combined
    average += smokeData[vendor];
  }
  average /= sizeof(tempData); // Divided by the leight of the array (average)

  Serial.Println(average); // Print the average of the Sensor
  return average; // Return back the Sensor average
}

void oneAnalogPin(int sensor) {
  /*
   * Reads the one port Analog Data and splits it to different sensors
   * Sensors using the same Port: MQ-2, LM35 & BTN;
   * When the sensor is required to get the analogRead value, all other sensors connected to the digital port has to be turned off
   * 
   * Parameters ==> "MQ2" || "LM35" || "BTN"
  */

  if (sensor == "MQ2") {
    digitalWrite(mq2Pin, LOW); // Turn ON the main Sensor
    digitalWrite(lm35Pin, LOW); // Turn off the LM35
    delay(20); // 20 miliseconds
  }
  else if (sensor == "LM35") {
    digitalWrite(lm35Pin, LOW); // Turn ON the main Sensor
    digitalWrite(mq2Pin, LOW); // Turn off the LM35
    delay(20); // 20 miliseconds
  }
  
  analogData = analogRead(analogPin); // Get value of the sensor choose and store it on a variable
  return analogData; // Return the value of the Analog Pin choosed
}

void hotspotServer(){
  /*
   * Starts the server
  */ 

  for (int index = 0; index < 3; index++) {
    changeLed(LedPin, HIGH); // Activate the LED calling a Function to do it
    delay(1000); // 1 second (1000 miliseconds)
  }
}

void searchForAlarm() {
  int alarm; // Variable of the alarm

  // Shows the server/sensors status on Serial Console
  Serial.Println("======================="); // Dividers
  Serial.Print("Server Status:"); // Server Status
  Serial.Println(arduServer);
  Serial.Print("Temperature:"); // Temp Sensor
  Serial.Println(tempSensor(howManyValues));
  Serial.Print("Smoke Status:"); // Smoke Sensor
  Serial.Println(smokeSensor(howManyValues));
  Serial.Println("=======================");


  while ((tempSensor(howManyValues)) == Precise_lm35 || (smokeSensor(howManyValues)) == Precise_mq2)) {
    Serial.Println("ALARM ACTIVATED!");

    for (int index = 0; index < 3; index++) {
      // Make the LED shine!
      Serial.Println(changeLed(LedPin, HIGH)); // Turn ON the LED and return's it status
      delay(500); // wait 500 miliseconds until led turns OFF
      Serial.Println(changeLed(LedPin, LOW)); // Turn OFF the LED and return's it status
    }
    makeSound(BuzzerPin); // Sound the Buzzer, make it loud!
  }
  else {
    Serial.Println("NOTHING DETECTED...yet");
    delay(1000); // 1 second of delay
  }
}

void SendWebData() {
  /*
   * This function sends the WebPage request to the client.
  */ 
}

void ReceiveWebData() {
  /*
   * This function is monitoring the instructions from the dashboard.
  */ 
}

void sendToDB(int valueToSend) {
  /*
   * This function is connected to a PHPmyadmin database and sends data
   * valueToSend => Data to send to the database
  */ 
  sprintf(query, INSERT_SQL, 1, valueToSend);
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(query);
  delete cur_mem;
  Serial.println("Data Sent to DataBase!");  
}

void restartArduino() {
  // NOTE: Digital Pin MUST be connected to Pin 'reset' on arduino
  Serial.println("Arduino is going to reset.");
  digitalWrite(reset, HIGH);
}

void print(int message) {
  /*
   * Print Recieved Data to LCD
   * This function recieves messages on parameters and prints 
   * it on LCD and organize on 16 by 2 acording to the leight of the text.
  */ 

  int printIt = message;
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print(millis() / 1000); // print the number of seconds since reset:

  lcd.print(message); // Print message
  delay(100); // 100 miliseconds

  if (sizeof(printIt) < 13) {
    // scroll 13 positions (string length) to the left
    // to move it offscreen left:
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      // wait a bit:
      delay(150);
    }
  }
}
