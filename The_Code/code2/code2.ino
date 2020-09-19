#include <TimerOne.h>
int counter=0;
int counter1=0;
int counter2=0;
#define SCR_PIN 3
#define SCR_PIN1 5
#define SCR_PIN2 6
int max_counter=0;
boolean zero_detect=false;
boolean zero_detect1=false;
boolean zero_detect2=false;
void phase_shift_counter()
{
  if(zero_detect&&counter>=max_counter)
  {
    digitalWrite(SCR_PIN,HIGH);
    zero_detect=false;
  }
  counter++;
}

void phase_shift_counter1()
{
  if(zero_detect1&&counter1>=max_counter)
  {
    digitalWrite(SCR_PIN1,HIGH);
    zero_detect1=false;
  }
  counter1++;
}

void phase_shift_counter2()
{
  if(zero_detect2&&counter2>=max_counter)
  {
    digitalWrite(SCR_PIN2,HIGH);
    zero_detect2=false;
  }
  counter2++;
}
void isr()
{
  zero_detect=true;
  counter=0;
  digitalWrite(SCR_PIN,LOW);

}

void isr1()
{
  zero_detect1=true;
  counter1=0;
  digitalWrite(SCR_PIN1,LOW);

}

void isr2()
{
  zero_detect2=true;
  counter2=0;
  digitalWrite(SCR_PIN2,LOW);

}
void setup() {
pinMode(SCR_PIN,OUTPUT);
pinMode(SCR_PIN1,OUTPUT);
pinMode(SCR_PIN2,OUTPUT);
Timer1.initialize(10);
Timer1.attachInterrupt(phase_shift_counter);
Timer1.initialize(10);
Timer1.attachInterrupt(phase_shift_counter1);
Timer1.initialize(10);
Timer1.attachInterrupt(phase_shift_counter2);
attachInterrupt(0,isr,RISING);
attachInterrupt(1,isr1,RISING);
attachInterrupt(1,isr2,RISING);
}

void loop() {
 
max_counter=map(analogRead(0),0,1023,0,1000);
}
