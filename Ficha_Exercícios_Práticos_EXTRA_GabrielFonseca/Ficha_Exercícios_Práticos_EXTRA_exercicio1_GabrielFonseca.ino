/*  
 * Dev by Gabriel.
 * 28/02/2021
*/
   
const int ledPin[] = {2, 4, 7, 8, 12};
const int potPin = A0;
int value, i;


void setup(){
    for (i = 0; i < sizeof(ledPin); i++) {
        pinMode(ledPin[i], OUTPUT);
    }
    pinMode(potPin, INPUT);
    Serial.begin(9600);
}

void loop(){
    value = analogRead(potPin);
    Serial.println(value);

    for (i = 0; i < sizeof(ledPin); i++) {
        digitalWrite(ledPin[i], HIGH);
        digitalWrite(ledPin[i], LOW);
        delay(value);
    }
}