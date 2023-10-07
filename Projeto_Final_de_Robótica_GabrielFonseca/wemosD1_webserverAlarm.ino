/*
 * Dev by Gabriel. 
 * WebServer project with Arduino D1.
 * More info on README.md file.
 * 13/07/2021
*/

#include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

/* NETWORK */
const char* ssid = "Vodafone-6079D7";
const char* pwd = "3EPffu2jud";

/* PORTS */
const int LedPin = 10; // LED Pin
const int BuzzerPin = 9; // Buzzer Pin
const int analogPin = A0; // AnalogPin

int analogData;

const int mq2Pin = 11;
const int lm35Pin = 12;

/* "GLOBAL" VARIABLES */
int lm35_value;
int mq2_value;

/* SENSORS PRECISELY */
// All values can change acording to the user dashboard!
int Precise_mq2 = 400; // Standard value (smoke)
int Precise_lm35 = 10; // Standard value (temperature º)

int howManyValues = 4; // Defauld, leight of the array

/* MYSQL DATABASE */
IPAddress server_addr(79,170,44,150); // MySql database IP adress
char user[] = "sql4424482"; // MySql User login
char password[] = "DGsTZJdEdI"; // MySql User password
char INSERT_SQL[] = "INSERT INTO sql4424482.alarm (id, serverStatus, data_sensorLM35, data_sensorMQ2) VALUES (%i, %s , %d, %a)";
char query[128];
int increment = 0;
int serverStatus = 1;

/* START OBJECTS */
WiFiClient client;
MySQL_Connection conn((Client *)&client); 

void setup() {
  /* OUTPUT PORTS */
  pinMode(LedPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(mq2Pin, OUTPUT);
  pinMode(lm35Pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);

  // Connect to the network
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    Serial.print( "." );
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println("Wifi Connected!");

  // print out information about the WIFI connection
  Serial.println ( "" );
  Serial.print ( "Connected to " );
  Serial.println ( ssid );
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );

  makeSound(BuzzerPin);

  // Connect to MySQL server
  Serial.println("Connecting to DB...");
  while (conn.connect(server_addr, 3306, user, password) != true) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    Serial.print( "." );
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println("Connected to SQL DB successfully");
}

void loop() {
  delay(2000);
  Serial.println("Recording data.");
  // Search for alarm
  searchForAlarm();

  // EX: sprintf(query, INSERT_SQL, +1, 1, 30, 50);
  sprintf(query, INSERT_SQL, increment, serverStatus, lm35_value, mq2_value);

  // Initiate the query class instance
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(query);
  delete cur_mem;

  increment++; // Increment +1
}

int changeLed(int pin, bool state) {
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
  
  int sound;
  
  for(sound = 700; sound < 800; sound++){
    tone(pin, sound);
    delay(15);
  }

  for(sound = 800; sound > 700; sound--){
    tone(pin, sound);
    delay(15);
  }
}

int smokeSensor(int precise) {
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
  
  Serial.println(average); // Print the average of the Sensor
  return average; // Return back the Sensor average
}

int tempSensor(int precise) {
  /*
   * Precise = How much precise will be the sensor
   * This function is monitoring the temperature get it by the LM35 sensor.
  */

  int reading = 0; // Variable to read
  int tempData[precise]; // Colects 4 output data to analyze
  int average = 0; // Average of the sensor

  for(int index = 0; index < sizeof(tempData); index++) {
    reading = (oneAnalogPin("LM35")); // ANALOG Sensor LM35 on PIN A0 
    delay(150); // Wait 150 miliseconds

    reading *= (5000 / 1024.0); // Convert the reading into voltage
    tempData[index] = reading / 10;  // Convert the voltage into the temperature in degree
    delay(150); // Wait 150 miliseconds
  }

  for (int vendor = 0; vendor < sizeof(tempData); vendor++) {
    // Averge of all data combined
    average += tempData[vendor];
  }
  average /= sizeof(tempData); // Divided by the leight of the array (average)

  Serial.println(average); // Print the average of the Sensor
  return average; // Return back the Sensor average
}

int oneAnalogPin(String sensor) {
  /*
   * Reads the one port Analog Data and splits it to different sensors
   * Sensors using the same Port: MQ-2, LM35 & BTN;
   * When the sensor is required to get the analogRead value, all other sensors connected to the digital port has to be turned off
   * 
   * Parameters ==> "MQ2" || "LM35"
  */

  if (sensor == "MQ2") {
    digitalWrite(mq2Pin, HIGH); // Turn ON main Sensor
    digitalWrite(lm35Pin, LOW); // Turn off LM35
    delay(20); // 20 miliseconds
  }
  else if (sensor == "LM35") {
    digitalWrite(lm35Pin, HIGH); // Turn ON main Sensor
    digitalWrite(mq2Pin, LOW); // Turn off MQ-2
    delay(20); // 20 miliseconds
  }
  
  analogData = analogRead(analogPin); // Return the value of the Analog Pin choosed
  Serial.println(analogData);
  return analogData;
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
  lm35_value = tempSensor(howManyValues);
  mq2_value = smokeSensor(howManyValues);

  // Shows the server/sensors status on Serial Console
  Serial.println("======================="); // Dividers
  Serial.print("Temperature:"); // Temp Sensor
  Serial.println(lm35_value);
  Serial.print("Smoke:"); // Smoke Sensor
  Serial.println(mq2_value);
  Serial.println("=======================");

  while (lm35_value == Precise_lm35 || mq2_value == Precise_mq2) {
    Serial.println("Alarm is activated");

    for (int index = 0; index < 3; index++) {
      // Make the LED shine!
      Serial.println(changeLed(LedPin, HIGH)); // Turn ON the LED and return's it status
      delay(500); // wait 500 miliseconds until led turns OFF
      Serial.println(changeLed(LedPin, LOW)); // Turn OFF the LED and return's it status
    }
    makeSound(BuzzerPin); // Sound the Buzzer, make it loud! 
  }
  delay(1000); // 1 second of delay
}
