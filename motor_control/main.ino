/*
 * Dev by Gabriel.
 * 16/04/2021
*/

const int motorPin = 10;
const int analogPin = A0;
const int LED = 12;
int speed = 0;
int output = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(0, buttonPressedON, RISING); // INTERRUPT CONDITION 0
  attachInterrupt(1, buttonPressedOFF, FALLING); // INTERRUPT CONDITION 1
  Serial.begin(3600); // SERIAL MONITOR
}

void loop() {
  // NOTHING HERE :D
}

void buttonPressedON() {
  digitalWrite(LED, HIGH); // TURN ON LED
  speed = analogRead(analogPin); // READ RESISTANCE VALUE
  output = map(speed, 0, 1023, 0, 255); // CALCULATE SPEED
  analogWrite(motorPin, output); // TURN ON MOTOR
  Serial.println(output);
}

void buttonPressedOFF() {
  digitalWrite(LED, LOW); // TURN OFF LED
  analogWrite(motorPin, 0); // TURN OFF MOTOR
}