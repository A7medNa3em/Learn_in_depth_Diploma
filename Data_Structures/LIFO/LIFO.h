/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : LIFO.h
 *      Description :APIs headers for LIFO (stack) data structure
 *
 */
#ifndef LIFO_H
#define LIFO_H

#define Element_DataType unsigned char

typedef struct
{
    Element_DataType *base;
    Element_DataType *top;
    Element_DataType data;
    unsigned int length;
    unsigned count;
} LIFO_t;

typedef enum
{
    Empty_LIFO,
    Not_Empty_LIFO,
    Full_LIFO,
    Not_Full_LIFO,
    Null_LIFO,
    Error_LIFO,
    NoError_LIFO,

} LIFO_Status;

/* LOFO APIs*/
void LIFO_Init(LIFO_t *p_buf, Element_DataType *buf, unsigned int length);
LIFO_Status LIFO_Push(LIFO_t *p_buf, Element_DataType item);
LIFO_Status LIFO_Pop(LIFO_t *p_buf, Element_DataType *item);

#endif