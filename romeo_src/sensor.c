#include "sensor.h"

void handle_obstacle ()
{
  int i;
  int left_avg = 0;
  int right_avg = 0;

  if (r == 1024)
    r = 0;

  for (i = 0; i < 5; i++)
    left_avg += analogRead(LEFT_SENSOR);

  for (i = 0; i < 5; i++)
    right_avg += analogRead(RIGHT_SENSOR);

  left_avg = left_avg / 5;
  right_avg = right_avg / 5;

  // zero obstacle in the both side
  if (left_avg < conf_sensor && right_avg < conf_sensor)
  {
    move_forward();
    delay (300);
  }
  // one obstacle on the left side
  else if (left_avg >= conf_sensor && right_avg < conf_sensor)
  {
    turn_right ();
    delay (300);
  }
  // one obstacle on the right side
  else if (right_avg >= conf_sensor && left_avg < conf_sensor)
  {
    turn_left ();
    delay (300);
  }
  else
  {
    stop_motor();
    move_backward();
    delay(500);
    if (r % 2)
      rotate_left();
    else
      rotate_right();
    r++;
    delay (1500);
  }
}
