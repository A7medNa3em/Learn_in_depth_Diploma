/*
 *       Author : Ahmed Naeem
 *       Date   :
 *       File   : US_sensor.h
 *
 */
#ifndef US_SENSOR_H
#define US_SENSOR_H

#include "state.h"

enum
{
    US_busy

} Us_State_Id;

/*Protypes*/

State_Define(US_busy);
void US_Init();

/*Global pointer to function*/
void (*US_State)();

#endif