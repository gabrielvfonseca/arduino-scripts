
int LED1 = 13;
int LED2 = 12;
int LED3 = 8;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  void start_LED1();
  void start_LED2();
  void start_LED3();
}

void start_LED1(){
  digitalWrite(LED1, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  delay(2000);
}

void start_LED2(){
  digitalWrite(LED2, HIGH);
  delay(2000);
  digitalWrite(LED2, LOW);
  delay(2000);
}

void start_LED3(){
  digitalWrite(LED3, HIGH);
  delay(2000);
  digitalWrite(LED3, LOW);
  delay(2000);
}
