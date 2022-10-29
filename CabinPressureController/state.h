/*
 ******************************************************************************
 * @file           : state.h
 * @author         : Ahmed Naeem
 * @brief          : state header file
 ******************************************************************************
 */

#ifndef STATE_H
#define STATE_H

/************************** State Genertator **************************/

/*State Function*/
#define Define_State(State_Func) void ST_##State_Func()
/*State Symbol*/
#define State(State_Func) ST_##State_Func

/************************** Transtions APIs **************************/

void SetPressureSensorVal(int PressureVal);
void LogSensorVal(int PressureVal, int status); // optional add time
void AlarmStatus(int status);

/************************** State machines **************************/

extern void (*PS_State)();
extern void (*CA_State)();
extern void (*Alarm_State)();

#endif
