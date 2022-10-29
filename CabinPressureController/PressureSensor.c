/*
 ******************************************************************************
 * @file           : PressureSensor.c
 * @author         : Ahmed Naeem
 * @brief          : Pressure sensor handeler
 ******************************************************************************
 */
#include "driver.h"
#include "PressureSensor.h"

/*Module Variables*/
int PS_Pressure;

void PS_Init()
{
    /*Intialize pressure sensor driver --> GPIO driver */
    /*Intialize with PS_Reading state*/
    PS_State = State(PS_busy);
}
Define_State(PS_busy)
{
    PS_Id = PS_busy;

    /*Read sensor value*/
    PS_Pressure = getPressureVal();
    /*send Pressure val value*/
    Delay(5000);
    SetPressureSensorVal(PS_Pressure);
}
