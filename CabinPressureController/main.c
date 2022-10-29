#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "state.h"

int main()
{
	/*Inilization*/
	PS_Init();
	CA_Init();
	Alarm_Init();
	GPIO_INITIALIZATION();

	while (1)
	{
		// Implement your Design

		PS_State();
		CA_State();
		Alarm_State();
	}
}
