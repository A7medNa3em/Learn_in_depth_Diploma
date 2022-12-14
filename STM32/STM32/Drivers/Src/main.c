/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "GPIO.h"
#include "stm32f103x6.h"
#include "LCD.h"

void mywait(uint8_t x)
{
	for(uint8_t i=0; i<x; i++)
	{
		for(uint8_t j=0; j<255; j++);
	}

}

/* RCC initliztion */
void RCC_Init()
{
	GPIOA_RCC_CLK_ENABLE();
	GPIOB_RCC_CLK_ENABLE();
}



int main(void)
{
	RCC_Init();
	MCAL_GPIO_GlobalInit();
	LCD_Init();


	/* Loop forever */
	while(1)
	{
		//		if(LOW == MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN1))
		//		{
		//			/* Single press*/
		//			MCAL_GPIO_TogglePin(GPIOB,GPIO_PIN1);
		//			while(LOW == MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN1));
		//		}
		//
		//		if(HIGH == MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN5))
		//		{
		//			/* Multi press*/
		//			MCAL_GPIO_TogglePin(GPIOB,GPIO_PIN5);
		//		}

		LCD_WriteString("LCD ON :)",10,0,0);
		mywait(100);
		LCD_ClearDisplay();
		mywait(100);

	}
}
