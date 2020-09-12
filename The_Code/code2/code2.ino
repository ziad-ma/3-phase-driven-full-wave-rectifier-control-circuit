#include <TimerOne.h>
int counter=0;
#define SCR_PIN 3
int max_counter=0;
boolean zero_detect=false;
void phase_shift_counter()
{
  if(zero_detect&&counter>=max_counter)
  {
    digitalWrite(SCR_PIN,HIGH);
    zero_detect=false;
  }
  counter++;
}
void isr()
{
  zero_detect=true;
  counter=0;
  digitalWrite(SCR_PIN,LOW);

}
void setup() {
pinMode(SCR_PIN,OUTPUT);
Timer1.initialize(10);
Timer1.attachInterrupt(phase_shift_counter);
attachInterrupt(0,isr,RISING);
}

void loop() {
 
max_counter=map(analogRead(0),0,1023,0,1000);
}
