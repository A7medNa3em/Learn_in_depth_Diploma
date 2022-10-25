/*
 *       Author : Ahmed Naeem
 *       Date   :
 *       File   : 
 *
 */

#include <stdio.h>
#include "ObsticalAvoidence_Algo.h"

int OA_speed = 0;
int OA_distance = 0;
int OA_threshold = 50;

void OA_Init()
{
    /*Init OA Algorthim*/
    OA_State = STATE(OA_Waiting);
    printf("Init OA Algorthim   >>> go into Waiting state \n");
}

void US_SendDistance(int d)
{
    OA_distance = d;

    printf("US_Sensor  ------------->> OA_Algorthim  \n");
    OA_distance > OA_threshold ? (OA_State = STATE(OA_Driving)) : (OA_State = STATE(OA_Waiting));
}

State_Define(OA_Waiting)
{
    OA_State_Id = OA_Waiting;
    OA_speed = 0;
    DC_getSpeed(OA_speed);
    printf("\tOA_Waiting state >> speed : %d >> distance : %d \n", OA_speed, OA_distance);
    printf("OA_Algorthim ---->> DC_Motor \n");
}
State_Define(OA_Driving)
{
    OA_State_Id = OA_Driving;
    OA_speed = 30;
    DC_getSpeed(OA_speed);
    printf("\tOA_Driving state >> speed : %d >> distance : %d \n", OA_speed, OA_distance);
    printf("OA_Algorthim ------------->> DC_Motor \n");
}
