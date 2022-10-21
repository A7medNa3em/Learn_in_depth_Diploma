/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : LinkedList.c
 *      Description :APIs body for Linked List data structure
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void ADD_Node(LL_Node **pp_Node)
{

    LL_Node *p_NewNode;
    LL_Node *p_LastNode;
    /* check if empty*/
    if (*pp_Node == NULL)
    {
        /*create new record */
        p_NewNode = (LL_Node *)malloc(sizeof(LL_Node));
        /* assign it to *pp_Node */
        *pp_Node = p_NewNode;
    }
    else
    {
        /* go to last node */
        p_LastNode = *pp_Node;
        while (p_LastNode->Next)
            p_LastNode = p_LastNode->Next;

        /*create new record */
        p_NewNode = (LL_Node *)malloc(sizeof(LL_Node));
        /* make last node points to new record */
        p_LastNode->Next = p_NewNode;
    }

    /* fill data*/
    Fill_Node(p_NewNode);

    /* make new record points to null*/
    p_NewNode->Next = NULL;
}

void Fill_Node(LL_Node *p_Node)
{
    char tempD[40];

    printf("\nENTER Student ID     : ");
    gets(tempD);
    p_Node->data.ID = atoi(tempD);

    printf("ENTER data Name   : ");
    gets(p_Node->data.name);

    printf("ENTER data Height : ");
    gets(tempD);
    p_Node->data.height = (float)atof(tempD);
}

LL_Status DisplayDATA(LL_Node **pp_Node)
{
    unsigned int count = 1;
    LL_Node *p_LastNode = *pp_Node;

    /* check if empty*/
    if (*pp_Node == NULL)
    {
        /*create new record */
        printf("========= Empty List =========");
        return Empty_List;
    }
    else
    {
        /* go to last node */
        while (p_LastNode)
        {
            printf("\n============= Record %d ================== ", count);
            printf("\n\t Student name   : %s ", p_LastNode->data.name);
            printf("\n\t Student ID     : %d ", p_LastNode->data.ID);
            printf("\n\t Student Hieght : %.2f ", p_LastNode->data.height);

            p_LastNode = p_LastNode->Next;
            count++;
        }
        return SUCCESS_DISPLAY;
    }
}

LL_Status DeleteNode_ID(LL_Node **pp_Node, unsigned int Selected_ID)
{

    LL_Node *previousStudent = NULL;
    LL_Node *currentStudent = *pp_Node;

    /*Loop for all data*/
    while (currentStudent)
    {
        /*check ID*/
        if (currentStudent->data.ID == Selected_ID)
        {
            if (previousStudent)
            {
                previousStudent->Next = currentStudent->Next;
            }
            else
            {
                /*first node*/
                *pp_Node = currentStudent->Next;
            }
            free(currentStudent);
            printf("Deleting node is done \n");
            return SUCCESS_DELETE_NODE;
        }

        previousStudent = currentStudent;
        currentStudent = currentStudent->Next;
    }

    printf("Can not find student \n");

    return FAILD_DELETE_NODE;
}

LL_Status DeleteNode_Nth(LL_Node **pp_Node, unsigned int Selected_n)
{
    unsigned char count = 1;

    LL_Node *previousStudent = NULL;
    LL_Node *currentStudent = *pp_Node;

    /*Loop for all data*/
    while (currentStudent)
    {
        /*check ID*/
        if (count == Selected_n)
        {
            if (previousStudent)
            {
                previousStudent->Next = currentStudent->Next;
            }
            else
            {
                /*first node*/
                *pp_Node = currentStudent->Next;
            }
            free(currentStudent);
            return FAILD_DELETE_NODE;
        }

        count++;
        previousStudent = currentStudent;
        currentStudent = currentStudent->Next;
    }

    printf("\n can not find student \n");

    return FAILD_DELETE_NODE;
}
LL_Status Delete_All(LL_Node **pp_Node)
{

    LL_Node *p_CurrentNode = *pp_Node;
    LL_Node *p_TemptNode = *pp_Node;

    /* check if empty*/
    if (*pp_Node == NULL)
    {
        return Empty_List;
    }
    else
    {
        /* go to last node */
        while (p_CurrentNode)
        {
            p_TemptNode = p_CurrentNode;
            p_CurrentNode = p_CurrentNode->Next;
            free(p_TemptNode);
        }
        *pp_Node = NULL;
        return SUCCESS_DELETE_NODE;
    }
}

unsigned int List_Length(LL_Node **pp_Node)
{

    /* check if empty*/
    if (*pp_Node == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + List_Length(&((*pp_Node)->Next)));
    }
}
