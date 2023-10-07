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
  // 3 LED States => 255/3 = 85
  for (brightness = 0; brightness <= 255; brightness += 85) {
    analogWrite(pinLED, brightness);
    Serial.println(brightness);
    delay(1000);
  }
}