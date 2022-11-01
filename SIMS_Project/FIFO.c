/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : FIFO.c
 *      Description :APIs for FIFO (queue) data structure
 *
 */

#include "FIFO.h"
#include <stdio.h>
#include <string.h>

FIFO_t gp_Student;

void FIFO_Init(FIFO_t *p_buf, Element_DataType *buf, unsigned int length)
{
    p_buf->length = length;
    p_buf->count = 0;

    p_buf->base = buf;
    p_buf->head = p_buf->base;
    p_buf->tail = p_buf->base;
}

FIFO_Status FIFO_IsFull(FIFO_t *p_buf)
{
    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->head || !p_buf->tail)
    {
        return Null_FIFO;
    }
    /* check if full */
    if (p_buf->count == p_buf->length)
    {
        return Full_FIFO;
    }
    else
        return Not_Full_FIFO;
}

FIFO_Status FIFO_Enqueue(FIFO_t *p_buf, Element_DataType item)
{
    // printf("get into push function \n");
    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->head || !p_buf->tail)
    {
        return Null_FIFO;
    }
    /* check if full */
    if (FIFO_IsFull(p_buf) == Full_FIFO)
    {
        printf("FIFO is Full \n");
        return Full_FIFO;
    }

    *(p_buf->head) = item;
    /*check circular FIFO*/
    if (p_buf->head == (p_buf->base + (p_buf->length) * sizeof(Element_DataType)))
        p_buf->head = p_buf->base;
    else
        p_buf->head++;

    p_buf->count++;

    // printf("Done Enqueue %d \n", item);
    return NoError_FIFO;
}

FIFO_Status FIFO_Dequeue(FIFO_t *p_buf, Element_DataType *item)
{
    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->head || !p_buf->tail)
    {
        return Null_FIFO;
    }
    /* check if empty */
    if (p_buf->count == 0)
    {
        printf("FIFO is empty \n");
        return Empty_FIFO;
    }

    *item = *(p_buf->tail);

    /*check circular FIFO*/
    if (p_buf->tail == (p_buf->base + (p_buf->length) * sizeof(Element_DataType)))
        p_buf->tail = p_buf->base;
    else
        p_buf->tail++;

    p_buf->count--;
    return NoError_FIFO;
}

int FIFO_FindId(FIFO_t *p_buf, Element_DataType *item, int Id)
{
    int tempcount = 0;
    Element_DataType *tempPtr = p_buf->tail;

    /* check if null */
    if (!p_buf || !p_buf->base || !p_buf->head || !p_buf->tail)
        return 0;

    if (p_buf->count == 0)
        return 0;

    while (tempPtr != p_buf->head)

    {
        // printf("%d\n", tempPtr->sid);
        if (tempPtr->sid == Id)
        {
            *item = *tempPtr;
            return 1;
        }
        tempcount++;
        tempPtr++;
    }
    return 0;
}

int FIFO_FindStr(FIFO_t *p_buf, Element_DataType item[10], char *Str)
{

    int count = 0;
    Element_DataType *tempPtr = p_buf->tail;
    /* check if null */

    if (!p_buf || !p_buf->base || !p_buf->head || !p_buf->tail)
    {
        return 0;
    }

    while (tempPtr != p_buf->head)
    {

        if (strcmp(tempPtr->fname, Str) == 0)
        {
            item[count] = *tempPtr;
            count++;
        }

        tempPtr++;
    }

    return count;
}
