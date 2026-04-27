#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int LR_BZ=6;
int ledbleu=4;
int trig=9;
int echo=10;
int distance;
int duration;
int firesensor=7;
int flame; //la boite du firesensor
int gazsensor = A0;
int gaz;
int watersensor=A1;
int water;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  Serial.begin (9600);
  pinMode (LR_BZ, OUTPUT);
  pinMode (ledbleu, OUTPUT);
  pinMode (firesensor, INPUT);
  pinMode (gazsensor, INPUT);
  pinMode (watersensor, INPUT);
  pinMode (echo, INPUT);
  pinMode (trig, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  //pour préparer l'alarme
 digitalWrite (trig, HIGH);
 delayMicroseconds (15);
 digitalWrite (trig, LOW);
 duration = pulseIN (echo,HIGH);
 distance= (0.034*duration)/2;
   flame= digitalRead(firesensor);
   gaz= analogRead(gazsensor);
   water= analogRead(watersensor);
   Serial.print("distance");
   Serial.printIn(distance);
   Serial.print("gaz");
   Serial.printIn(gaz);
   Serial.print("flame");
   Serial.printIn(flame);
   Serial.print("water");
   Serial.printIn(water);
     lcd.clear();
     if (distance<10 && water <=300 && gaz>=100 && flame==0){
     digitalWrite (LR_BZ,HIGH);
     digitalWrite (ledbleu,LOW);
     lcd.setCursor (4,0);
     lcd.print("Attention");
     lcd.setCursor (0,1);  
     lcd.print("Tous les Danger!!");   
     } else if (distance<10 && water>300 && gaz<100 && flame==1){
     digitalWrite (LR_BZ,HIGH);
     digitalWrite (ledbleu,LOW);
     lcd.setCursor (4,0);
     lcd.print("Attention");
     lcd.setCursor (0,1);  
     lcd.print("Danger! Voleur");  
     }
     else if (distance>10 && water>300 && gaz>=100 && flame==1){
     digitalWrite (LR_BZ,HIGH);
     digitalWrite (ledbleu,LOW);
     lcd.setCursor (4,0);
     lcd.print("Attention");
     lcd.setCursor (0,1);  
     lcd.print("Danger! GAZ");
     }
     else if (distance>10 && water>300 && gaz<100 && flame==0){
     digitalWrite (LR_BZ,HIGH);
     digitalWrite (ledbleu,LOW);
     lcd.setCursor (4,0);
     lcd.print("Attention");
     lcd.setCursor (0,1);  
     lcd.print("Danger! Flame");
     }
     else if (distance>10 && water<=300 && gaz<100 && flame==1){
     digitalWrite (LR_BZ,HIGH);
     digitalWrite (ledbleu,LOW);
     lcd.setCursor (4,0);
     lcd.print("Attention");
     lcd.setCursor (0,1);  
     lcd.print("Danger! Water");
     }
     else if (distance>10 && water>300 && gaz<100 && flame==1){
     digitalWrite (LR_BZ,LOW);
     digitalWrite (ledbleu,HIGH);
     lcd.setCursor (2,0);
     lcd.print("Hello Friend");
     lcd.setCursor (1,1);  
     lcd.print("You are Safe");
     }
}
