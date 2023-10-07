/*
 * Dev by Gabriel 
 * 17/02/2021
*/

int brightness = 0;
int pinLED = 9;

void setup(){
  pinMode(pinLED, OUTPUT);
}

void loop(){
  for (brightness = 0; brightness <= 255; brightness += 10) {
    analogWrite(pinLED, brightness);
    Serial.println(brightness);
    delay(10);
  }
}