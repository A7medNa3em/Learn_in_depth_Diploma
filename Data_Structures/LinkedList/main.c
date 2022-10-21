/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : main.c
 *      Description :Student Database by Linked List
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/* Databases */
LL_Node *gp_Student = NULL;

void main()
{
    unsigned int choice, buf, flag = 1;

    while (flag)
    {
        printf("\n==================================");
        printf("\nChoose from this Options \n");
        printf("1-Add Student \n");
        printf("2- Delete Student by ID \n");
        printf("3- Delete Student by index \n");
        printf("4-Display Data base \n");
        printf("5- Number of Students \n");
        printf("6-Clear Student Database\n");

        printf("\nEnter Operation : ");
        scanf("%d", &choice);
        fflush(stdin);
        fflush(stdout);

        switch (choice)
        {
        case 1:
        {
            ADD_Node(&gp_Student);
        }
        break;
        case 2:
        {
            printf("================================== \n");
            printf("Enter Student ID : ");
            scanf("%d", &buf);
            fflush(stdin);
            fflush(stdout);

            DeleteNode_ID(&gp_Student, buf);
        }
        break;
        case 3:
        {
            printf("================================== \n");
            printf("Enter Index : ");
            scanf("%d", &buf);
            fflush(stdin);
            fflush(stdout);

            DeleteNode_Nth(&gp_Student, buf);
        }
        break;
        case 4:
        {
            DisplayDATA(&gp_Student);
        }
        break;
        case 5:
        {
            printf("Number of students %d \n", List_Length(&gp_Student));
        }
        break;
        case 6:
        {
            printf("All Student is deleted \n");
            Delete_All(&gp_Student);
        }
        break;
        default:
        {
            printf("Wrong Choice\n");
        }
        break;
        }

        printf("\n\nMore operation Enter (1) \t Exit Enter (0) \n");
        scanf("%d", &flag);
        fflush(stdin);
        fflush(stdout);
    }
}
