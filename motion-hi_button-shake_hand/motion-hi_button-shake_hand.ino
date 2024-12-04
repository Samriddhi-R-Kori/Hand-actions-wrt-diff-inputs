#include <Servo.h>
int b = 4;
int sw;

Servo palm;
Servo arm;
int p = 10; //palm pin
int m = 110; //middle
int r = 50; //right
int l = 170; //left

int a = 8; //arm pin
int d = 0; //down
int up = 200; //up
int s = 90; //shake hand point

int pos;

int pirPin = 2;
int pirStat = 0;

void setup()
{
  pinMode(b, INPUT);
  digitalWrite(b, HIGH);

  palm.attach(p);
  palm.write(m);
  arm.attach(a);
  arm.write(d);

  pinMode(pirPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  pirStat = digitalRead(pirPin);
  sw = digitalRead(b);
  delay(250);

  if (pirStat == HIGH)
  {
    for (pos = d; pos <= up; pos += 1)
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
    palm.write(r);
    delay(250);
    palm.write(l);
    delay(250);
    palm.write(m);
    delay(250);
  }

  if (sw == LOW)
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
  {
    palm.write(m);
    arm.write(d);
  }
}
