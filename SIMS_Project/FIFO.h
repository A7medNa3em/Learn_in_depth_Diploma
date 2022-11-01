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

#include "StudentsDB.h"
#define Element_DataType struct SSinfo

typedef struct
{
    Element_DataType *base;
    Element_DataType *head;
    Element_DataType *tail;
    unsigned int length;
    unsigned count;
} FIFO_t;

extern FIFO_t gp_Student;

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
int FIFO_FindId(FIFO_t *p_buf, Element_DataType *item, int Id);
int FIFO_FindStr(FIFO_t *p_buf, Element_DataType item[10], char *Str);

#endif