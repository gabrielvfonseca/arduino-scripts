int led1 = 9;
int led2 = 10;
char var;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop(){
  if (Serial.available()>0) {
    var = Serial.read();
    switch(var){
      case 'a':
        digitalWrite(led1, HIGH);
        break;
      case 'b':
        digitalWrite(led2, HIGH);
        break;
      case 'c':
        digitalWrite(led2, LOW);
        break;
      case 'd':
        digitalWrite(led2, LOW);
        break;
    }
  }
}
