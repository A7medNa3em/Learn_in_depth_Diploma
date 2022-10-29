/*
 ******************************************************************************
 * @file           : alarm.c
 * @author         : Ahmed Naeem
 * @brief          : handle alarm operation
 ******************************************************************************
 */

#include "driver.h"
#include "alarm.h"

void Alarm_Init()
{
    /*Intialize alarm driver---> GPIO */
    /*Intialize with PS_Reading state*/
    Alarm_State = State(Alarm_Off);
}
void AlarmStatus(int status)
{
    status == 0 ? (Alarm_State = State(Alarm_Off)) : (Alarm_State = State(Alarm_On));
}
Define_State(Alarm_On)
{
    Alarm_Id = Alarm_On;
    Set_Alarm_actuator(1);
    Delay(600000);
    Set_Alarm_actuator(0);
}
Define_State(Alarm_Off)
{
    Alarm_Id = Alarm_Off;
    Set_Alarm_actuator(0);
}