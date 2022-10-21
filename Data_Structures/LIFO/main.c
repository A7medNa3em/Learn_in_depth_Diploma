/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : main.c
 *      Description :APIs for LIFO (stack) data structure
 *
 */
#include <stdio.h>
#include "LIFO.h"

void main()
{
    LIFO_t stack;
    unsigned char buf[5];
    unsigned char temp;

    LIFO_Init(&stack, buf, 5);

    printf("return status %d ", LIFO_Push(&stack, 1));
    LIFO_Push(&stack, 2);
    LIFO_Push(&stack, 3);
    LIFO_Push(&stack, 4);

    for (int i = 0; i < 5; i++)
    {
        LIFO_Pop(&stack, &temp);
        printf(" %d \n", temp);
    }
}
