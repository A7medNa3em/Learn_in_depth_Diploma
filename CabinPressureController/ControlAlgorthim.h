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
    CA_NormalPressure,
    CA_HighPressure

} CA_Id;

void CA_Init();
Define_State(CA_NormalPressure);
Define_State(CA_HighPressure);

void (*CA_State)();

#endif