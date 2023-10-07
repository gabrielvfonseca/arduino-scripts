const int buttonPin = 2; // Botão
const int ledPin =  8; // Arduino Digital LED Pin

int buttonState = 0; // variavel de estado do botão

void setup() {
  Serial.begin(9600); // Monitor serial
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Ler estado do botão (1 / 0)
  buttonState = digitalRead(buttonPin);

  if (buttonState == true) {
    // Se o Botão for acionado, o LED acende (1)
    Serial.write("1 (aceso)\n");
    digitalWrite(ledPin, HIGH);
    delay(1000); // Tempo do LED ligado
  } 
  
  else {
    // Se o Botão não for acionado, o LED mantem-se apagado (0)
    Serial.write("0 (apagado)\n");
    digitalWrite(ledPin, LOW);
  }
  delay(1000); // Tempo de espera antes de reiniciar o ciclo
}