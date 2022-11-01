/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : StudentsDB.c
 *      Description : APIs body for
 *                   simple student database
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentsDB.h"
#include "FIFO.h"

struct SSinfo SDB[STUDNUM];

/* Add Student From known File*/
RETURN_STATUS AddS_FromFile(char *filename)
{
    char ReadBuffer[100];
    char buf;
    unsigned int index = 0, currentString = 0;

    struct SSinfo Stemp;

    /*Open file */
    FILE *fptr = NULL;

    fptr = fopen(filename, "r");

    /*Check if file exist */
    if (fptr == NULL)
    {
        printf("File %s is not existed \n", filename);
        return Failed_OP;
    }
    /*Read from file*/
    // go along file
    while (1)
    {
        buf = (char)fgetc(fptr);
        // printf("%c", buf);
        if (feof(fptr))
        {
            return SUCCESS_OP;
            break;
        }
        if (buf == ' ')
        {
            ReadBuffer[index] = '\0';
            if (currentString == 0)
                strcpy(Stemp.fname, ReadBuffer);
            else if (currentString == 1)
                strcpy(Stemp.lname, ReadBuffer);
            else if (currentString == 2)
                Stemp.sid = (int)atoi(ReadBuffer);
            else if (currentString == 3)
                Stemp.gpa = (float)atof(ReadBuffer);
            else
            {
                for (int k = 0; k < 8; k++)
                {
                    if (currentString == k + 4)
                        Stemp.courseid[k] = (int)atoi(ReadBuffer);
                }
            }
            index = 0;
            currentString++;
            continue;
        }
        else if (buf == '\n')
        {
            currentString = 0;
            index = 0;

            /*  Unique ID Check */
            if (0 == FIFO_FindId(&gp_Student, &Stemp, Stemp.sid))
            {
                /*enqueue */
                if (FIFO_Enqueue(&gp_Student, Stemp) == NoError_FIFO)
                {

                    // DisplayStudent(Stemp);
                    printf("[Done]-->Insert New Student  \n");
                }
                else
                {
                    printf("[ERORR]-->Can not insert Student \n");
                    return Failed_OP;
                }
            }
            else
            {
                // printf("[ERORR]--> ID %d is inserted before\n", Stemp.sid);
            }
            continue;
        }
        else
        {
            ReadBuffer[index] = buf;
        }

        index++;
    }

    fclose(fptr);
}

/* Add Student Manual*/
RETURN_STATUS AddS_Manual()
{

    struct SSinfo Stemp;
    char tempD[20];
    int tempint;

    /*Take Data from user*/
    printf("Enter First Name  : ");
    gets(Stemp.fname);

    printf("Enter Last  Name  : ");
    gets(Stemp.lname);

    printf("Enter Student ID  : ");
    gets(tempD);
    tempint = atoi(tempD);

    /*  Unique ID Check */
    if (0 != FIFO_FindId(&gp_Student, &Stemp, tempint))
    {
        printf("[ERORR]--> ID %d is inserted before\n", Stemp.sid);
        return Failed_OP;
    }
    else
    {
        Stemp.sid = tempint;
    }

    printf("Enter Courses ID  : ");
    for (int i = 0; i < 8; i++)
    {
        gets(tempD);
        Stemp.courseid[i] = atoi(tempD);
    }

    printf("Enter Student GPA : ");
    gets(tempD);
    Stemp.gpa = (float)atof(tempD);

    /*Enqueue student at Queue*/
    if (FIFO_Enqueue(&gp_Student, Stemp) == NoError_FIFO)
    {
        printf("[Done]--> Insert student \n");
        DisplayStudent(Stemp);
    }
    else
    {
        printf("[ERORR]-->Can not insert Student \n");
        return Failed_OP;
    }
}

/*Find Student by ID */
RETURN_STATUS FindS_ById(int Sid)
{
    struct SSinfo Stemp;

    if (0 == FIFO_FindId(&gp_Student, &Stemp, Sid))
    {
        printf("[ERORR]--> Student Id is not found\n");
        return Failed_OP;
    }
    else
    {
        printf("[Done]--> Student is found\n");
        DisplayStudent(Stemp);
        return SUCCESS_OP;
    }
}

/*Find Student by First name */
RETURN_STATUS FindS_ByFname(char *Sfname)
{
    struct SSinfo Stemp[10];
    int count = FIFO_FindStr(&gp_Student, Stemp, Sfname);

    if (0 == count)
    {
        printf("[ERORR]--> Student with this name is not found\n");
        return Failed_OP;
    }
    else
    {
        printf("[Done]--> There are %d student found\n", count);
        for (int i = 0; i < count; i++)
        {
            DisplayStudent(Stemp[i]);
        }
        return SUCCESS_OP;
    }
}

/*Find Students Registered in same Course*/
RETURN_STATUS FindS_InCourse(int CourseId)
{

    int studCount = 0;
    /* Go along Students */

    Element_DataType *tempPtr = gp_Student.tail;

    /* check if null */
    if (!gp_Student.base || !gp_Student.head || !gp_Student.tail)
        return Failed_OP;

    if (gp_Student.count == 0)
        return Failed_OP;

    while (tempPtr != gp_Student.head)
    {
        /* go alonng courses id*/
        for (int i = 0; i < 8; i++)
        {
            /* if course found print student details*/
            if (tempPtr->courseid[i] == CourseId)
            {
                DisplayStudent(*tempPtr);
                studCount++;
                break;
            }
        }
        tempPtr++;
    }

    /*print number of student in course*/
    printf("Number of students in course %d id %d students\n", CourseId, studCount);

    return SUCCESS_OP;
}

/*Find Students counts in DB */
int SCounts()
{
    return gp_Student.count;
}

/* Delete Student */
RETURN_STATUS DeleteS(int Sid)
{
    struct SSinfo Stemp;
    int foundflag = 0;
    while (gp_Student.count != foundflag)
    {
        FIFO_Dequeue(&gp_Student, &Stemp);
        if (Stemp.sid == Sid)
        {
            DisplayStudent(Stemp);
            printf("[Done]--> Student is Deleted \n");
            return SUCCESS_OP;
            break;
        }
        else
        {
            FIFO_Enqueue(&gp_Student, Stemp);
            foundflag++;
        }
    }
    printf("[ERORR]--> Student Id is not found\n");
    return Failed_OP;
}

/* Update Student */
RETURN_STATUS UpdateS(int Sid)
{
    struct SSinfo Stemp;
    int foundflag = 0;
    while (gp_Student.count != foundflag)
    {
        FIFO_Dequeue(&gp_Student, &Stemp);
        if (Stemp.sid == Sid)
        {
            printf("[Done]--> Enter Student New data\n");
            DisplayStudent(Stemp);
            /*take new data */
            AddS_Manual();
            return SUCCESS_OP;
            break;
        }
        else
        {
            // printf("[Student Id is Not Found HERE]\n");
            FIFO_Enqueue(&gp_Student, Stemp);
            foundflag++;
        }
    }
    printf("[ERORR]--> Student Id is not found\n");
    return Failed_OP;
}

/*Show Students */
RETURN_STATUS ShowDB()
{
    /* Go along Students */
    Element_DataType *tempPtr = gp_Student.tail;

    /* check if null */
    if (!gp_Student.base || !gp_Student.head || !gp_Student.tail)
        return Failed_OP;

    if (gp_Student.count == 0)
        return Failed_OP;

    while (tempPtr != gp_Student.head)
    {
        DisplayStudent(*tempPtr);
        tempPtr++;
    }
}

void DisplayStudent(struct SSinfo stud)
{
    printf("=====================================\n");
    printf("\tName    : %s %s\n", stud.fname, stud.lname);
    printf("\tID      : %d \n", stud.sid);
    printf("\tCourses : %d", stud.courseid[0]);
    for (int i = 1; i < 8; i++)
    {
        printf(" , %d", stud.courseid[i]);
    }
    printf("\n\tGPA     : %.1f \n", stud.gpa);
    printf("=====================================\n");
}

RETURN_STATUS StoreInFile(char *filename)
{
    FILE *fptr = NULL;
    Element_DataType *tempPtr = gp_Student.tail;
    char tempStr[5];

    /*Read From file to avoid insert same data*/
    AddS_FromFile(filename);
    /*Delte comtent of file*/
    fptr = fopen(filename, "w");
    fclose(fptr);

    fptr = fopen(filename, "a+");
    if (fptr == NULL)
        return Failed_OP;

    /* check if null */
    if (!gp_Student.base || !gp_Student.head || !gp_Student.tail)
        return Failed_OP;

    if (gp_Student.count == 0)
        return Failed_OP;

    /* Go along Students */
    while (tempPtr != gp_Student.head)
    {
        fprintf(fptr, tempPtr->fname);
        fprintf(fptr, " ");
        fprintf(fptr, tempPtr->lname);
        fprintf(fptr, " ");

        sprintf(tempStr, "%d", tempPtr->sid);
        fprintf(fptr, tempStr);
        fprintf(fptr, " ");

        sprintf(tempStr, "%.1f", tempPtr->gpa);
        fprintf(fptr, tempStr);
        fprintf(fptr, " ");

        for (int i = 0; i < 8; i++)
        {
            sprintf(tempStr, "%d", tempPtr->courseid[i]);
            fprintf(fptr, tempStr);
            fprintf(fptr, " ");
        }
        fprintf(fptr, "\n");
        printf("=");

        tempPtr++;
    }
    fclose(fptr);

    return SUCCESS_OP;
}