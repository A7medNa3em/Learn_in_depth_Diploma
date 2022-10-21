/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : FIFO.h
 *      Description : Data types and APIs headers
 *                    for FIFO (queue) data structure
 *
 */

#ifndef FIFO_H
#define FIFO_H

#define Element_DataType unsigned char

typedef struct
{
    Element_DataType *base;
    Element_DataType *head;
    Element_DataType *tail;
    unsigned int length;
    unsigned count;
} FIFO_t;

typedef enum
{
    Empty_FIFO,
    Not_Empty_FIFO,
    Full_FIFO,
    Not_Full_FIFO,
    Null_FIFO,
    Error_FIFO,
    NoError_FIFO,

} FIFO_Status;

/* FOFO APIs*/
void FIFO_Init(FIFO_t *p_buf, Element_DataType *buf, unsigned int length);
FIFO_Status FIFO_Enqueue(FIFO_t *p_buf, Element_DataType item);
FIFO_Status FIFO_Dequeue(FIFO_t *p_buf, Element_DataType *item);

#endif