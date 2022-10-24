/*
 *       Author : Ahmed Naeem
 *       Date   :
 *       File   : state.h
 *
 */

#ifndef OA_AlGORITHM_H
#define OA_AlGORITHM_H

#include "state.h"

enum
{
    OA_Waiting,
    OA_Driving

} OA_State_Id;

void OA_Init();
State_Define(OA_Waiting);
State_Define(OA_Driving);

void (*OA_State)();

#endif