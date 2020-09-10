#define value A0 //Vsine/in
#define rate A1 //varuable risistor
void setup()
{
 pinMode(11,OUTPUT);
}

void loop()
{
 float x=analogRead(rate);
 if(x>=511.5)
 {
   float v= 2*x;
  statment1(v);
}else statment2(v);
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
      delayMicroseconds(20);
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
      delayMicroseconds(20);
    }
  }
}
