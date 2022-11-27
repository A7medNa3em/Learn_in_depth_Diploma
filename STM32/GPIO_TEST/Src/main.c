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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define uint32_t unsigned int
/*************** Registers ********************/
/*********** GPIO *******************/
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL   *((volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH   *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_IDR   *((volatile uint32_t *)(GPIOA_BASE + 0x08))
#define GPIOA_ODR   *((volatile uint32_t *)(GPIOA_BASE + 0x0c))

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRL   *((volatile uint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH   *((volatile uint32_t *)(GPIOB_BASE + 0x04))
#define GPIOB_IDR   *((volatile uint32_t *)(GPIOB_BASE + 0x08))
#define GPIOB_ODR   *((volatile uint32_t *)(GPIOB_BASE + 0x0c))

/*********** RCC ***********/
#define RCC_BASE 0x40021000
#define RCC_CFGR   *((volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_APB2ENR   *((volatile uint32_t *)(RCC_BASE + 0x18))

#define GET_BIT(Reg,bit) ((Reg & (1<<bit)) >> bit)

/******* INIT functions ******/

void RCC_Init()
{
	// Enable RCC for Port A
	RCC_APB2ENR |= (1<<2);
	// Enable RCC for Port B
	RCC_APB2ENR |= (1<<3);
}

void GPIO_Init()
{
	// Port A  PIN 1 & 13 as Floating Input
	GPIOA_CRL &= ~(0b11<<6);
	GPIOA_CRL |= (1<<6);

	GPIOB_CRH &= ~(0b11<<22);
	GPIOA_CRH |= (1<<22);

	// Port B Pin 1 as Push Pull output
	GPIOB_CRL &= ~(0b11<<6);
	GPIOB_CRL |= (0b1<<4);

	// Port B Pin 13 as open drain output
	GPIOB_CRH &= ~(0b11<<22);
	GPIOB_CRH |= (0b0101<<20);
}


void Rwait(int x)
{
	for(int i=0; i<=x;i++)
		for(int j=0; j<255;j++);
}

int main(void)
{
	RCC_Init();
	GPIO_Init();

	while(1)
	{
		//PA1 single press --> PB1 led Toggle

		if (GET_BIT(GPIOA_IDR,1) == 0)
		{
			GPIOB_ODR ^= (1<<1);
		while (GET_BIT(GPIOA_IDR,1)==0);

		}

		//PA13 multi press --> led toggle
		if (GET_BIT(GPIOA_IDR,13) == 1)
		{
			GPIOB_ODR ^= (1<<13);
		}
		Rwait(2);

	}


}
