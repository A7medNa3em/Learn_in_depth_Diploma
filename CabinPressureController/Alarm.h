/*
 ******************************************************************************
 * @file           : ControlAlgorthim.h
 * @author         : Ahmed Naeem
 * @brief          : Control sequencesa APIs
 ******************************************************************************
 */

#ifndef CONTROLALGORTHIM_H
#define CONTROLALGORTHIM_H

#include "state.h"
enum
{
    Alarm_On,
    Alarm_Off

} Alarm_Id;

void Alarm_Init();
Define_State(Alarm_On);
Define_State(Alarm_Off);

void (*Alarm_State)();

#endif