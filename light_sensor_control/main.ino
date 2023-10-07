/*
 * Dev by Gabriel 
 * 26/02/2021
*/

#include <LiquidCrystal.h>

#define pinoLed 9 
int pinoSensorLuz = A0;
int media, soma, output;  
int array[4];

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 
void setup(){
  pinMode(pinoLed,OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);     
}
 
void loop(){ 
  // Call functions
  luz();
  
  // What to Display
  if(media <= 400){
    Serial.println("Less 400"); 
    output = map(media, 0, 1023, 0, 10);
    analogWrite(pinoLed, output);  
  }
  else if(media > 400 && media <= 450){   
    output = map(media, 0, 1023, 0, 25);
    analogWrite(pinoLed, output);             
  }
  else if(media > 450 && media <= 500){
    output = map(media, 0, 1023, 0, 50);
    analogWrite(pinoLed, output); 
  }
  else if(media > 500 && media <= 550){  
    output = map(media, 0, 1023, 0, 80);
    analogWrite(pinoLed, output);               
  }
  else if(media > 550 && media <= 600){
    output = map(media, 0, 1023, 0, 100);
    analogWrite(pinoLed, output);                 
  }
  else if(media > 600 && media <= 650){
    output = map(media, 0, 1023, 0, 150);
    analogWrite(pinoLed, output);                 
  }
  else if(media > 650 && media <= 700){
    output = map(media, 0, 1023, 0, 200);
    analogWrite(pinoLed, output);                
  }
  else if(media > 700){       
    Serial.println("Up 700");
    output = map(media, 0, 1023, 0, 255);
    analogWrite(pinoLed, output);          
  }
  delay(500);                   
}

void luz(){
  Serial.println("Reading data...");
  array[0] = analogRead(pinoSensorLuz);
  delay(100); 
  array[1] = analogRead(pinoSensorLuz);
  delay(100);
  array[2] = analogRead(pinoSensorLuz);  
  delay(100);
  array[3] = analogRead(pinoSensorLuz); 

  soma = (array[0] + array[1] + array[2] + array[3]);
  media = soma /4;

  lcd.setCursor(0,1);
  lcd.print(media);
}

void ecra(){
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}