/**
**

** \file sensor.h
** \brief define the function to handle obstacle through sensor
** \author Arthur LAMBERT
** \date 05//05/2012
**
**/

#ifndef SENSOR_H_
# define SENSOR_H_

#include "motor.h"
#include "WProgram.h"


#define LEFT_SENSOR = 0; // pin analog 0
#define RIGHT_SENSOR = 2; // pin analog 2
#define CONF_SENSOR = 190;

/* use value send by sensor to handle obstacle */
void handle_obstacle ();

#endif /* !SENSOR_H_ */
