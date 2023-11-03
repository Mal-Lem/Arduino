int ledbleu=5;
int ledrouge=4;
int buzzar=6;
int capteurincendit=9;
int capteurgaz=A0;
int gazstate;
int incenditstate;

void setup() {
  Serial.begin(9600);
  pinMode(ledbleu,OUTPUT);
 pinMode(ledrouge,OUTPUT);
 pinMode(capteurgaz,INPUT);
 pinMode(capteurincendit,INPUT);
 pinMode(buzzar,OUTPUT);
}

void loop() {
 gazstate = analogRead(A0);
 incenditstate= digitalRead(9);
 Serial.println(gazstate);
 if((gazstate>250)||(incenditstate==LOW))
{
  digitalWrite(4,HIGH);
  delay(99);
  digitalWrite(4,LOW);
  delay(99);
  digitalWrite(5,LOW);
  digitalWrite(buzzar,HIGH);
}
else
{
if((gazstate<=250)&&(incenditstate==HIGH))
{
   digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(buzzar,LOW);
}
}
}
