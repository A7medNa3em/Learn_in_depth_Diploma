#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include "state.h"

enum
{
    DC_Idle,
    DC_busy

} DC_State_Id;

/*Protypes*/

State_Define(DC_Idle);
State_Define(DC_busy);

void DC_Init();

/*Global pointer to function*/
void (*DC_State)();

#endif