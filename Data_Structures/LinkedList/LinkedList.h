/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : LinkedList.h
 *      Description :APIs headers for Linked List data structure
 *
 */
#ifndef LINLED_LIST_H
#define LINLED_LIST_H

typedef enum
{
    Empty_List,
    SUCCESS_ADD_NODE,
    SUCCESS_DISPLAY,
    FAILD_ADD_NODE,
    SUCCESS_DELETE_NODE,
    FAILD_DELETE_NODE,

} LL_Status;

typedef struct
{
    char name[40];
    unsigned int ID;
    float height;

} Sdata;

struct Node
{
    Sdata data;
    struct Node *Next;
};
typedef struct Node LL_Node;

void ADD_Node(LL_Node **pp_Node);
void Fill_Node(LL_Node *p_Node);
LL_Status DisplayDATA(LL_Node **pp_Node);
LL_Status DeleteNode_ID(LL_Node **pp_Node, unsigned int Selected_ID);
LL_Status DeleteNode_Nth(LL_Node **pp_Node, unsigned int Selected_n);
unsigned int List_Length(LL_Node **pp_Node);
LL_Status Delete_All(LL_Node **pp_Node);

#endif