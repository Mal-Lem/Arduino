/* ta carte tesa digital ya atesekhesidh ya atechaledh tezemredh asetaredh bouton ma d analogue di chida ma attas ma chitt asetarnudh la résistence
wigad isan pwm zemredh ateneteskhedmedh i analogue*/


//int button=5;
int led=6;
int R=A0;
int state;
void setup()
{
pinMode(led,OUTPUT);
pinMode(R,INPUT);
//pinMode(button,INPUT);
}

void loop() {
  
/*digitalWrite(ledbleu,HIGH);
delay(150);
digitalWrite(ledbleu,LOW);
delay(150);
state= digitalRead(button);
digitalWrite(led,state);*/

state=analogRead(R);
analogWrite(led,state);

}
