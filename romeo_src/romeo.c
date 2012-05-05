#include "motor.h"
#include "sensor.h"

void setup(void)
{
  int i;
  for (i = 6; i <= 9; i++)
    pinMode(i, OUTPUT);

  Serial.begin(19200);
  move_forward();
}
void loop(void)
{
  handle_obstacle();
  move_forward();
  delay(15);
}

