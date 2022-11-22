#include "stdtypes.h"
#include "bitmath.h"

#include <util/delay.h>
#include <avr/interrupt.h>

#define FallngEdge
/*****************Registers*****************/
#define SREG (*(volatile unsigned char *)0X5F)
#define GICR (*(volatile unsigned char *)0X5B)
#define MCUCR (*(volatile unsigned char *)0X55)
#define MCUCSR (*(volatile unsigned char *)0X54)

#define DDRD (*(volatile unsigned char *)0X31)
#define PORTD (*(volatile unsigned char *)0X32)
#define PIND (*(volatile unsigned char *)0X30)

ISR(INT0_vect)
{
    // DDRD = 0xff;
    PORTD |= 1 << 5;
    _delay_ms(1000);
}

ISR(INT1_vect)
{
    // DDRD = 0xff;
    PORTD |= 1 << 6;
    _delay_ms(1000);
}

ISR(INT2_vect)
{
    // DDRD = 0xff;
    PORTD |= 1 << 7;
    _delay_ms(1000);
}

void EXTI_init()
{
    // specfiy senstivity
    // Risig , falling edge or high , level for INT0 or INT1 in MCUCR

    // Falling edge for interrupt zero
    SET_BIT(MCUCR, 0);
    CLR_BIT(MCUCR, 1);

    // LOW Level for interrupt 1
    CLR_BIT(MCUCR, 2);
    SET_BIT(MCUCR, 3);

    // Risig edge for INT2 in MCUCR ISC2 bit --> 6
    SET_BIT(MCUCSR, 6);

    // Enable INTx in GICR
    // INT0 --> bit 6
    SET_BIT(GICR, 6);
    // INT1 --> bit 7
    SET_BIT(GICR, 7);
    // INT2 --> bit 5
    SET_BIT(GICR, 5);

    //  enable I flag in SREG --> bit 7
    SET_BIT(SREG, 7);
}

void main()
{
    // Init portd as output
    DDRD |= (1 << 5) | (1 << 6) | (1 << 7);

    EXTI_init();

    while (1)
        ;
}
