#include "uart.h"

unsigned char String_buffer[100] = "Learn-in-depth <Ahmed Naeem>";

void main(void)
{
    Uart_Write_string(String_buffer);
}