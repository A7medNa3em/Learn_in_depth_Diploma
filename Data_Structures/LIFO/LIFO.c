/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : LIFO.c
 *      Description :APIs for LIFO (stack) data structure
 *
 */
#include "LIFO.h"
#include <stdio.h>

void LIFO_Init(LIFO_t *p_buf, Element_DataType *buf, unsigned int length)
{
    p_buf->length = length;
    p_buf->count = 0;

    p_buf->base = buf;
    p_buf->top = p_buf->base;
}

LIFO_Status LIFO_IsFull(LIFO_t *p_buf)
{
    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->top)
    {
        return Null_LIFO;
    }
    /* check if full */
    if (p_buf->top == (p_buf->base + p_buf->length))
    {
        return NoError_LIFO;
    }
    else
        return Not_Full_LIFO;
}

LIFO_Status LIFO_Push(LIFO_t *p_buf, Element_DataType item)
{
    // printf("get into push function \n");
    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->top)
    {
        return Null_LIFO;
    }
    /* check if full */
    if (LIFO_IsFull(p_buf) == Full_LIFO)
    {
        return Error_LIFO;
    }

    *(p_buf->top) = item;
    p_buf->top++;
    p_buf->count++;

    printf("Done push %d \n", item);
    return NoError_LIFO;
}
LIFO_Status LIFO_Pop(LIFO_t *p_buf, Element_DataType *item)
{
    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->top)
    {
        return Null_LIFO;
    }
    /* check if empty */
    if (p_buf->top == p_buf->base)
    {
        return Empty_LIFO;
    }
    p_buf->top--;
    *item = *(p_buf->top);
    p_buf->count--;
    return NoError_LIFO;
}