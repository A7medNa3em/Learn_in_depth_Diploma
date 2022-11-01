/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : main.c
 *      Description :Student Database by Queue
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentsDB.h"
#include "FIFO.h"

void main()
{

    unsigned int choice, buf, flag = 1;
    char sbuf[20];

    /* FIFO Init*/
    FIFO_Init(&gp_Student, SDB, STUDNUM);

    while (flag)
    {
        printf("\n==================================");
        printf("\nChoose from this Options \n");
        printf("1- Add Student From File \n");
        printf("2- Add Student Manually \n");
        printf("3- Find Student by ID \n");
        printf("4- Find Student by first name\n");
        printf("5- Number of Students \n");
        printf("6- Delete Student by ID \n");
        printf("7- Find Student in Course number\n");
        printf("8- Update Student \n");
        printf("9- Display Database \n");
        printf("10- Save Database \n");

        printf("\nEnter Operation : ");
        scanf("%d", &choice);
        fflush(stdin);
        fflush(stdout);

        switch (choice)
        {
        case 1:
        {
            AddS_FromFile("data.txt");
        }
        break;
        case 2:
        {
            printf("================================== \n");
            AddS_Manual();
        }
        break;
        case 3:
        {
            printf("================================== \n");
            printf("Enter Student ID : ");
            scanf("%d", &buf);
            fflush(stdin);
            fflush(stdout);

            FindS_ById(buf);
        }
        break;
        case 4:
        {
            printf("================================== \n");
            printf("Enter Student first name : ");
            gets(sbuf);
            fflush(stdin);
            fflush(stdout);

            FindS_ByFname(sbuf);
        }
        break;
        case 5:
        {
            printf("Number of students : %d \t", SCounts());
            printf("Avalible Seats : %d \n", STUDNUM - SCounts());
        }
        break;
        case 6:
        {
            printf("================================== \n");
            printf("Enter Student ID to be deleted : ");
            scanf("%d", &buf);
            fflush(stdin);
            fflush(stdout);

            DeleteS(buf);
        }
        break;
        case 7:
        {
            printf("================================== \n");
            printf("Enter Course number : ");
            scanf("%d", &buf);
            fflush(stdin);
            fflush(stdout);

            FindS_InCourse(buf);
        }
        break;
        case 8:
        {
            printf("================================== \n");
            printf("Enter Student ID to be updated : ");
            scanf("%d", &buf);
            fflush(stdin);
            fflush(stdout);

            UpdateS(buf);
        }
        break;
        case 9:
        {
            ShowDB();
        }
        break;
        case 10:
        {
            printf("\nSAVING DATA ");
            StoreInFile("DB.txt");
        }
        break;
        }
        printf("\n\nMore operation Enter (1) \t Exit Enter (0) \n");
        scanf("%d", &flag);
        fflush(stdin);
        fflush(stdout);
    }
}
