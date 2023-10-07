int limiteDisparo = 600;
int led = 9;
int sensor = A0;
int sensorValue = 0;
 
void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}
 
void loop(){
  sensorValue = analogRead(sensor);
  if (sensorValue < limiteDisparo) {
      digitalWrite(led, HIGH);
  }
  else {
      digitalWrite(led,LOW);
  }
  
  Serial.print ("Leitura atual do sensor: ");
  Serial.println(sensorValue);
  delay(130);
}
