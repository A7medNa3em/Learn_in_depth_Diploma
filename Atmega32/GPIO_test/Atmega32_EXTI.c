#include "stdtypes.h"
#include "bitmath.h"

#include <util/delay.h>

/*****************Registers*****************/
#
#define DDRD (*(volatile unsigned char *)0X31)
#define PORTD (*(volatile unsigned char *)0X32)
#define PIND (*(volatile unsigned char *)0X30)

void main()
{
    // Init port d pin 4,5,6,7 as output
    DDRD |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

    while (1)
    {
        // led 5
        SET_BIT(PORTD, 5);
        CLR_BIT(PORTD, 6);
        CLR_BIT(PORTD, 7);
        CLR_BIT(PORTD, 4);

        _delay_ms(1000);
        // led 6
        CLR_BIT(PORTD, 5);
        SET_BIT(PORTD, 6);
        CLR_BIT(PORTD, 7);
        CLR_BIT(PORTD, 4);
        _delay_ms(1000);

        // led 7
        CLR_BIT(PORTD, 5);
        CLR_BIT(PORTD, 6);
        SET_BIT(PORTD, 7);
        CLR_BIT(PORTD, 4);
        _delay_ms(1000);

        // buzzer
        CLR_BIT(PORTD, 5);
        CLR_BIT(PORTD, 6);
        CLR_BIT(PORTD, 7);
        SET_BIT(PORTD, 4);
        _delay_ms(1000);
    }
}
