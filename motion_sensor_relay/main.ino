/*  
 * Dev by Gabriel.
 * 28/02/2021
*/
   
const int pinPIR = 5;
const int pinRelay = 3;
const int pinAnalog = A0;
int output[2];
 
void setup(){
  pinMode(pinRelay, OUTPUT);
  pinMode(pinPIR, INPUT);
  Serial.begin(3600);
}

void loop(){
 output[0] = digitalRead(pinPIR);
 output[1] = analogRead(pinAnalog);
 output[2] = digitalRead(pinRelay);


 if(output[0] == HIGH || output[1] == HIGH){
    digitalWrite(pinRelay, HIGH); // turn on relay
    Serial.println("Relay Status = ON");
    delay(4000);
 }
 else{
    digitalWrite(pinRelay, LOW); // turn off relay
    Serial.println("Relay Status = OFF");
    delay(1000);
 }
}