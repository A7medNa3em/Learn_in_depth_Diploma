/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Naeem
 * @brief          : Main program body
 ******************************************************************************

 */

typedef unsigned long unint32_t;
typedef unsigned char uint8_t;

#define GPIO_PORTF_DIR_R (*((volatile unint32_t *)0x40025400))
#define GPIO_PORTF_DATA_R (*((volatile unint32_t *)0x400253FC))
#define GPIO_PORTF_DEN_R (*((volatile unint32_t *)0x4002551C))

#define SYSCTCL_RCGC2_R (*((volatile unint32_t *)0x400FE108))

static unint32_t bss_var[25];
int main(void)
{
	volatile unint32_t i;
	SYSCTCL_RCGC2_R = 0x00000020;

	for (i = 0; i < 500; i++)
		;
	GPIO_PORTF_DIR_R |= 1 << 3;
	GPIO_PORTF_DEN_R |= 1 << 3;

	while (1)
	{
		GPIO_PORTF_DATA_R |= 1 << 3;
		for (i = 0; i < 500000; i++)
			;
		GPIO_PORTF_DATA_R &= ~(1 << 3);
		for (i = 0; i < 500000; i++)
			;
	}

	return 0;
}
