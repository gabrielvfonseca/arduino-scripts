int analog=A0;
int led=13;
int limite=400;

 void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 }
 void loop(){
  int avalor = analogRead(analog);
  if(avalor > limite) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  Serial.println(avalor);
  delay(1000);
 }
