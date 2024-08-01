#include <SoftwareSerial.h>

int speed_a = 0;
int speed_b = 0;
char blt = ' ' ;
SoftwareSerial bt(2, 3); //rx, tx

void Bluetooth();
void left();
void forward();
void backward();
void right();
void stp();

void setup()
{
  bt.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  speed_a = 50;
  speed_b = 50;
  blt = 'A';


}

void loop()
{
  Bluetooth();
}

void right()
{
  analogWrite(5, speed_a);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  analogWrite(10, map (speed_b, 0, 255, 255, 0) );
}

void left()
{
  analogWrite(5, map (speed_b, 0, 255, 255, 0) );
  digitalWrite(6, HIGH);
  digitalWrite(9, LOW);
  analogWrite(10, speed_a);
}

void forward()
{
  analogWrite(5, speed_a);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  analogWrite(10, ( speed_b - 30 ));
}

void backward()
{
  analogWrite(5, map (speed_a, 0, 255, 255, 0) );
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  analogWrite(10, map (speed_b, 0, 255, 255, 0) );
}

void stp()
{
  digitalWrite(6, LOW);
  analogWrite(5, 0);
  digitalWrite(9, LOW);
  analogWrite(10, 0);
}

void Bluetooth()
{
  if (bt.available())
  {
    Serial.print(blt);
    Serial.println();
    blt = bt.read();
    if (blt == 'f')
    {
      forward();
    }
    if (blt == 'b')
    {
      backward();
    }
    if (blt == 'r')
    {
      right();
    }
    if (blt == 'l')
    {
      left();
    }
    if (blt == 's')
    {
      stp();
    }
  }
}
