
#include <stdio.h>
#include "DC_Motor.h"
#include <stdlib.h>

/*Module Variable*/

int speed = 0;

void DC_Init()
{
    /*init DC sensor driver*/
    printf("Init DC motor driver >>> go into Idel state \n*\n*\n");
    DC_State = STATE(DC_Idle);
}

void DC_getSpeed(int s)
{
    speed = s;
    DC_State = STATE(DC_busy);
}

State_Define(DC_Idle)
{
    /*state action*/
    DC_State_Id = DC_Idle;

    DC_State = STATE(DC_busy);

    printf("\tDC_Idle State >> speed : %d \n\n", speed);
}

State_Define(DC_busy)
{
    /*state action*/
    DC_State_Id = DC_busy;

    DC_State = STATE(DC_Idle);

    printf("\tDC_busy State  >> speed : %d \n\n", speed);
}
