/*
 ******************************************************************************
 * @file           : ControlAlgorthim.c
 * @author         : Ahmed Naeem
 * @brief          : Control sequencesa
 ******************************************************************************
 */

#include "driver.h"
#include "ControlAlgorthim.h"

int CA_Pressure;
int ThressholdPressure = 20;

void SetPressureSensorVal(int PressureVal)
{
    CA_Pressure = PressureVal;
    /*Checking pressure*/
    CA_Pressure < ThressholdPressure ? (CA_State = State(CA_NormalPressure)) : (CA_State = State(CA_HighPressure));
}

void CA_Init()
{
    /*Inilze no drivers to init */
    /*in CA_NormalPressure state */
    CA_State = State(CA_NormalPressure);
}
Define_State(CA_NormalPressure)
{
    CA_Id = CA_NormalPressure;
    /*Send Pressure value to flash*/
    // LogSensorVal(CA_Pressure, 0);
    AlarmStatus(0);
}
Define_State(CA_HighPressure)
{
    CA_Id = CA_HighPressure;

    /*Send Pressure value to flash*/
    // LogSensorVal(CA_Pressure, 1);
    AlarmStatus(1);
}