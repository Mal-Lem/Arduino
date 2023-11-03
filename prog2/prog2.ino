int ledbleu=7;
int ledrouge=8;
int buzzar=6;
int detecteur=5;
int state;

void setup() {
 pinMode(ledbleu,OUTPUT);
 pinMode(ledrouge,OUTPUT);
 pinMode(detecteur,INPUT);
 pinMode(buzzar,OUTPUT);
}

void loop() {
state = digitalRead(detecteur);

if(state==LOW)
{
  digitalWrite(ledrouge,HIGH);
  digitalWrite(ledbleu,LOW);
  digitalWrite(buzzar,LOW);
}
else
{
if(state==HIGH)
{
   digitalWrite(ledbleu,HIGH);
  digitalWrite(ledrouge,LOW);
  digitalWrite(buzzar,HIGH);
}
}
}
