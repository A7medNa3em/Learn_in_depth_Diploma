/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : main.c
 *      Description :main app
 *
 */
#include <stdio.h>
#include "FIFO.h"

void main()
{
    FIFO_t queue;
    unsigned char buf[5] = {0};
    unsigned char temp;

    FIFO_Init(&queue, buf, 5);

    printf("return status %d ", FIFO_Enqueue(&queue, 100));
    FIFO_Enqueue(&queue, 2);
    FIFO_Enqueue(&queue, 55);
    FIFO_Enqueue(&queue, 90);
    FIFO_Enqueue(&queue, 50);
    FIFO_Enqueue(&queue, 60);
    FIFO_Enqueue(&queue, 70);

    for (int i = 0; i < 7; i++)
    {
        FIFO_Dequeue(&queue, &temp);
        printf(" %d \n", temp);
    }
}
