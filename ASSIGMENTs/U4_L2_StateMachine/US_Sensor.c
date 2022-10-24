/*
 *       Author : Ahmed Naeem
 *       Date   :
 *       File   : US_sensor.c
 *
 */

#include <stdio.h>
#include "US_Sensor.h"
#include <stdlib.h>

/*Module Variable*/

int distance = 0;

/* get random data simulate sensor read value*/
int GetRandomVal(int min, int max)
{
    unsigned int rand_val = (rand() % (max - min + 1)) + min;
    return rand_val;
}

void US_Init()
{
    /*init Us sensor driver*/
    US_State = STATE(US_busy);

    printf("Init US driver      >>> go into busy    state \n");
}

State_Define(US_busy)
{
    /*state action*/
    Us_State_Id = US_busy;

    /*read sensor value*/
    distance = GetRandomVal(45, 55);

    printf("-----------> US_Sensor\n");

    printf("\tUS_busy State >> Distance : %d \n", distance);

    /*send value to OA_Algrothim*/
    US_SendDistance(distance);

    US_State = STATE(US_busy);
}