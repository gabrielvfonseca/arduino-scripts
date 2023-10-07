/*
 * Dev by Gabriel 
 * 26/02/2021
*/

#include <LiquidCrystal.h>

#define pinoLed 9  // LED 
int pinoSensorLuz = A0;  // SENSOR LUZ
int array[4]; // ARRAY
int media; // VARIÁVEIS PARA A MÉDIA E SOMA DE VALORES
int soma;
int output; // VARIÁVEIS INTENSIDADE DO LED

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // BIBLIOTECA LCD, NESTE CASO AS PORTAS ONDE O LCD ESTÁ CONECTADO
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup(){
  pinMode(pinoLed, OUTPUT); // DEFENIR PORTA DO LED COMO OUTPUT
  lcd.begin(16, 2); // INICIALIZA O ECRÃ LCD, 'LCD.BEGIN' FAZ PARTE DA BIBLIOTECA IMPORTADA
  Serial.begin(9600);  // INICIALIZA MONITOR SERIAL
}
 
void loop(){ 
  luz(); // CHAMA FUNÇÃO 'LUZ()'
  
  if(media <= 400){
    Serial.println("Less 400"); // ENVIA MENSAGEM PARA O MONITOR SERIAL
    output = map(media, 0, 1023, 0, 10); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED
  }
  else if(media > 400 && media <= 450){  // DEFINE UMA CONDIÇÃO NUM DETERMINADO INTERVALO DE VALORES
    output = map(media, 0, 1023, 0, 25); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED   
  }
  else if(media > 450 && media <= 500){ // DEFINE UMA CONDIÇÃO NUM DETERMINADO INTERVALO DE VALORES
    output = map(media, 0, 1023, 0, 50); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED
  }
  else if(media > 500 && media <= 550){ // DEFINE UMA CONDIÇÃO NUM DETERMINADO INTERVALO DE VALORES
    output = map(media, 0, 1023, 0, 80); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED            
  }
  else if(media > 550 && media <= 600){ // DEFINE UMA CONDIÇÃO NUM DETERMINADO INTERVALO DE VALORES
    output = map(media, 0, 1023, 0, 100); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED             
  }
  else if(media > 600 && media <= 650){ // DEFINE UMA CONDIÇÃO NUM DETERMINADO INTERVALO DE VALORES
    output = map(media, 0, 1023, 0, 150); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED              
  }
  else if(media > 650 && media <= 700){ // DEFINE UMA CONDIÇÃO NUM DETERMINADO INTERVALO DE VALORES
    output = map(media, 0, 1023, 0, 200); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED            
  }
  else if(media > 700){       
    Serial.println("Up 700"); // ENVIA MENSAGEM PARA O MONITOR SERIAL
    output = map(media, 0, 1023, 0, 255); // DETERMINA A INTENSIDADE DO LED (pwm)
    analogWrite(pinoLed, output); // ENVIA OS VALORES PARA O LED
  }
  delay(500); // ESPERA 500 MILISEGUNDOS            
}

void luz(){ // FUNÇÃO 'LUZ()' QUE É CHAMADA SEMPRE QUE FOR NECESSÁRIO RECEBER VALORES E EFETUAR A MÉDIA
  Serial.println("Reading data..."); // COLOCA NO MONITOR SERIAL UMA MENSAGEM
  array[0] = analogRead(pinoSensorLuz); // LÊ O VALOR DO SENSOR E DEFINE COMO VALOR DA VARIAVEL 
  delay(500); // ESPERA 500 MILISEGUNDOS
  array[1] = analogRead(pinoSensorLuz); // LÊ O VALOR DO SENSOR E DEFINE COMO VALOR DA VARIAVEL 
  delay(500); // ESPERA 500 MILISEGUNDOS
  array[2] = analogRead(pinoSensorLuz); // LÊ O VALOR DO SENSOR E DEFINE COMO VALOR DA VARIAVEL 
  delay(500); // ESPERA 500 MILISEGUNDOS
  array[3] = analogRead(pinoSensorLuz); // LÊ O VALOR DO SENSOR E DEFINE COMO VALOR DA VARIAVEL 

  soma = (array[0] + array[1] + array[2] + array[3]); // SOMA TODOS OS VALORES OBTIDOS
  media = soma /4; // DIVIDE PELO VALOR DE NÚMEROS OBTIDOS, OU SEJA, FAZ A MÉDIA
 
  lcd.setCursor(0,1); // DEFINE A PORPURÇÃO DO ECRÃ LCD
  lcd.print(media); // ENVIA A MÉDIA FINAL PARA O ECRÃ LCD
}

//  FUNÇÃO COM INFORMAÇÕES DA BIBLIOTECA DO LCD
void ecra(){ 
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
