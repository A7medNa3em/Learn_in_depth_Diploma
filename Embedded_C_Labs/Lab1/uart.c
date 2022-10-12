
#define UART0DR *((volatile unsigned int *)((unsigned int *)0x101f1000))

void Uart_Write_string(unsigned char *str)
{
    while (*str != '\0')
    {
        UART0DR = *str;
        str++;
    }
}