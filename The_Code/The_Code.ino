#define value A0
#define rate A1
void setup()
{
 pinMode(11,OUTPUT);
}

void loop()
{
 float x=analogRead(rate);
 if(x>=511.5)
 {
  statment1(x);
 }else statment2(x);
}
void statment1(float z)
{
  float a=analogRead(value);
  float b=a;
  delayMicroseconds(5);
  a=analogRead(value);
  if(a>b)
  {
    if(a==z)
    {
      digitalWrite(11,HIGH);
    }
  }
}
void statment2(float z)
{
  float a=analogRead(value);
  float b=a;
  delayMicroseconds(5);
  a=analogRead(value);
  if(a<b)
  {
    if(a==z)
    {
      digitalWrite(11,HIGH);
    }
  }
}
