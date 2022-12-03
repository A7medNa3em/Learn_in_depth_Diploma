#ifndef KEYPAD_CFG_H
#define KEYPAD_CFG_H

typedef struct
{
	uint16_t keypin;
	GPIOx_t*  keyport;
} KEY_t;

typedef struct
{

	/*Rows are outputs*/
	KEY_t rows[4];

	/*colums are iuputs*/
	KEY_t cols[4];

	/*default state*/
	STATE_t defState;

} KeypadConfg_t;

extern KeypadConfg_t Keypads[];
extern uint8_t KeypadsCount;
#endif
