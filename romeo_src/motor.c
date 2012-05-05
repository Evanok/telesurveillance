#include "motor.h"

void move_forward()
{
  analogWrite (E2, SPEED);
  digitalWrite(M2,LOW);
  analogWrite (E1, SPEED);
  digitalWrite(M1,HIGH);
}

void move_backward()
{
  analogWrite (E2, SPEED);
  digitalWrite(M2,HIGH);
  analogWrite (E1, SPEED);
  digitalWrite(M1,LOW);
}

void turn_right ()
{
  analogWrite (E2, 0);
  digitalWrite(M2,LOW);
  analogWrite (E1, SPEED);
  digitalWrite(M1,HIGH);
}

void turn_left ()
{
  analogWrite (E2, SPEED);
  digitalWrite(M2,LOW);
  analogWrite (E1, 0);
  digitalWrite(M1,HIGH);
}

void rotate_right ()
{
  analogWrite (E2, SPEED);
  digitalWrite(M2,HIGH);
  analogWrite (E1, SPEED);
  digitalWrite(M1,HIGH);
}

void rotate_left ()
{
  analogWrite (E2, SPEED);
  digitalWrite(M2,LOW);
  analogWrite (E1, SPEED);
  digitalWrite(M1,LOW);
}

void stop_motor ()
{
  analogWrite (E1, 0);
  analogWrite (E2, 0);
}











