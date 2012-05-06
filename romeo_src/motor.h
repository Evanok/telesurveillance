/**
**

** \file motor.h
** \brief define the motor functions
** \author Arthur Lambert
** \date 05/05/2012
**
**/

#ifndef MOTOR_H_
# define MOTOR_H_

#include "Arduino.h"

#define E1 5     //M1 Speed Control
#define E2 6     //M2 Speed Control
#define M1 4    //M1 Direction Control
#define M2 7    //M1 Direction Control

#define SPEED 200

/* move forward */
void move_forward();
/* move backward */
void move_backward();
/* move forward in the right direction */
void turn_right ();
/* move forward in the left direction */
void turn_left ();
/* rotate in the right side */
void rotate_right ();
/* rotate in the left side */
void rotate_left ();
/* stop the wheel */
void stop_motor ();




#endif /* !MOTOR_H_ */
