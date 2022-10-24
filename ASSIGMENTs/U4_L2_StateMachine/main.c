/*
 *       Author : Ahmed Naeem
 *       Date   :
 *       File   : state.h
 *
 */
#include "DC_Motor.h"
#include "US_Sensor.h"
#include "ObsticalAvoidence_Algo.h"

void setup()
{
    /* States Inits*/

    US_Init();
    OA_Init();
    DC_Init();
}

void main()
{
    setup();

    while (1)
    {
        US_State();
        OA_State();
        DC_State();

        for (int i = 0; i < 50000000; i++)
            ;
    }
}