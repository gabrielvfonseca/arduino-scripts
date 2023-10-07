/*
 * Dev by Gabriel.
 * If the Distance Sensor calls the interrupt
 * on the Arduino, a Buzzer with different sound levels
 * and a LED are going to be activated.
 * 23/04/2021
*/

// == Define Ports ==========
#define LED 8
#define buzzerPin 9
const int analogPin = A0;

// == Program Variables =====
const int buzzerVolume = 255;
int lightValues[4];
int inches = 0;
int cm = 0;
int sensorReading;

long readUltrasonicDistance(int triggerPin, int echoPin) {
    pinMode(triggerPin, OUTPUT);  // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Sets the trigger pin to HIGH state for 10 microseconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    return pulseIn(echoPin, HIGH);
}

void setup() {
    // == Ports + Serial ========
    pinMode(LED, OUTPUT); // LED OUTPUT
    pinMode(analogPin, INPUT); // A0 INPUT
    pinMode(buzzerPin, OUTPUT); // BUZZER OUTPUT
    Serial.begin(9600);

    // == Interupts =============
    attachInterrupt(3, sensorInterruptON, RISING);
    attachInterrupt(3, sensorInterruptOFF, FALLING);
}

void loop() {
    // DO NOTHING :D
}

void setDefine(int value, int status) {
  // Function to turn ON/OFF a specific PIN
  digitalWrite(value, status);
}

void distanceSensor() {
    // measure the ping time in cm
    cm = 0.01723 * readUltrasonicDistance(7, 7);
    // convert to inches by dividing by 2.54
    inches = (cm / 2.54);
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.println("cm");
    delay(100); // Wait for 100 millisecond(s)
}

void lightSensor() {
  //Reads Light sensor data and determinates his precison
  for (int i = 0; i < 4; i++) { // Read Light sensor data
    lightValues[i] = analogRead(analogPin);
    delay(15);
  }
  lightValues[4] = ((lightValues[0] + lightValues[1] + lightValues[2] + lightValues[3])/4); // Calculate average of the light sensor
}

void buzzer() {
    tone(9, 440 * pow(2.0, (constrain(int(map(buzzerVolume, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
    delay(50); // Delay a little bit to improve simulation performance
}

void sensorInterruptON() {
    lightSensor(); // Calls lightSensor function
    distanceSensor(); // Calls distance measure function

    if (lightValues[4] >= 500 || cm >= 10) {
        while (true) {
            buzzer(); // Calls buzzer function
            setDefine(LED, HIGH); // Turns ON the LED by function
            delay(1500);
    }
  }
}

void sensorInterruptOFF() {
    setDefine(LED, LOW); // Turns OFF the LED by function
}