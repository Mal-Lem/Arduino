int ledbleu=5;
int ledrouge=4;
int ledvert=7;
int buzzar=6;
int capteur_eau=A0;
int capteur_incendit=9;
int state_eau;
int state_incendit;

void setup() {
 Serial.begin(9600);
  pinMode(ledbleu,OUTPUT);
 pinMode(ledrouge,OUTPUT);
 pinMode(ledvert,OUTPUT);
 pinMode(capteur_eau,INPUT);
 pinMode(capteur_incendit,INPUT);
 pinMode(buzzar,OUTPUT);
}

void loop() {
 state_eau = analogRead(A0);
 state_incendit= digitalRead(9);
Serial.println(state_eau);
if (state_eau<=100 || state_incendit==HIGH)
{
 digitalWrite(7,HIGH);
 digitalWrite(5,LOW);
 digitalWrite(4,LOW);
 digitalWrite(6,HIGH);
}
else
{if((state_eau<=700)&&(state_eau>100))
{
  digitalWrite(5,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
  }
  else{ if (state_eau>700 ){
   digitalWrite(4,HIGH);
 delay(99);
 digitalWrite(4,LOW);
 delay(99);
 digitalWrite(5,LOW);
 digitalWrite(7,LOW);
 digitalWrite(6,HIGH);
  }
  }}
}
