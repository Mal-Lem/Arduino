/*hasas l masafa ihattev lewaqt ni itettataf lmawja akn adughal ar l matèriel ink aprés attesekhedmedh l relation ni d=t*v */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledbleu=5;
int ledrouge=6;
int buzzar=7;
int distance_echo=8;
int distance_trig=9;
int d;
int t;


void setup() {
  Serial.begin(9600);
 pinMode(ledbleu,OUTPUT);
 pinMode(ledrouge,OUTPUT);
 pinMode(buzzar,OUTPUT);
 pinMode(distance_trig,OUTPUT);
 pinMode(distance_echo,INPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  digitalWrite(9,HIGH);
  delayMicroseconds(15);
  digitalWrite(9,LOW);
  
  t= pulseIn(8,HIGH);
  d=((0.034*t)/2);/*vitesse du song 3400ms*/
   lcd.clear();
 lcd.setCursor (1,0);
 lcd.println(d);
 delay(500);
  if(d>10)
  {
       digitalWrite(ledbleu,HIGH);
    digitalWrite(ledrouge,LOW);
    digitalWrite(buzzar,LOW);
 
  }  else if(d<=1450) {
    digitalWrite(ledbleu,LOW);
    digitalWrite(ledrouge,HIGH);
    digitalWrite(buzzar,HIGH);
    
   
    }
  }
