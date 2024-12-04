#include <Servo.h>
int b=4;
int sw;

Servo palm;
Servo arm;
int p = 10; //palm pin
int m = 110; //middle
int r = 50; //right
int l = 170; //left

int a = 8; //arm pin
int d = 0; //down
int s = 90; //shake hand point

int pos;

void setup()
{
  pinMode(b,INPUT);
  digitalWrite(b,HIGH);
  palm.attach(p);
  palm.write(m);
  arm.attach(a);
  arm.write(d);
  Serial.begin(9600);
}

void loop()
{
  sw=digitalRead(b);
  delay(250);
  Serial.println(sw);
  
  if(sw==LOW)
  {
  for (pos = d; pos <= s; pos += 1)
  {
    arm.write(pos);
    delay(10);
  }
   palm.write(m);
  delay(250);
  palm.write(r);
  delay(250);
  palm.write(l);
  delay(250);
  palm.write(m);
  delay(250);
  palm.write(r);
  delay(250);
  palm.write(l);
  delay(250);
  palm.write(m);
  delay(250);
  }

  else
  palm.write(m);
  arm.write(d);
}
