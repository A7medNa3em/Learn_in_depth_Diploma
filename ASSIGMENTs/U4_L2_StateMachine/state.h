/*
 *       Author : Ahmed Naeem
 *       Date   :
 *       File   : state.h
 *
 */

#ifndef STATE_H
#define STATE_H

/* Function Generator */
/*Function*/
#define State_Define(state_func) void ST_##state_func()
/*Symbol*/
#define STATE(state_func) ST_##state_func

/* Transtions APIs (state connections)*/
void US_SendDistance(int d);
void DC_getSpeed(int s);

#endif