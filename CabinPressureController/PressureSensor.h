/*
 ******************************************************************************
 * @file           : PressureSensor.h
 * @author         : Ahmed Naeem
 * @brief          : Pressure sensor handeler
 ******************************************************************************
 */

#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include "state.h"

enum
{
    PS_busy,

} PS_Id;

void PS_Init();
Define_State(PS_busy);

void (*PS_State)();

#endif