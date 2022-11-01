/*
 *      Author      : Ahmed Naeem
 *      Date        :
 *      File        : StudentsDB.h
 *      Description : Data types and APIs headers
 *                   simple student database
 *
 */

#ifndef STUDENTSDB_H
#define STUDENTSDB_H

typedef enum
{
    Failed_OP,
    SUCCESS_OP

} RETURN_STATUS;

struct SSinfo
{
    char fname[20];
    char lname[20];
    int sid;
    int courseid[8];
    float gpa;
};

/************ Student Databases by queue ***********/
#define STUDNUM 50
extern struct SSinfo SDB[STUDNUM];

/******************** APIs ***********************/

/* Add Student From known File*/
RETURN_STATUS AddS_FromFile(char *filename);

/* Add Student Manual*/
RETURN_STATUS AddS_Manual();

/*Find Student by ID */
RETURN_STATUS FindS_ById(int Sid);

/*Find Student by First name */
RETURN_STATUS FindS_ByFname(char *Sfname);

/*Find Students Registered in same Course*/
RETURN_STATUS FindS_InCourse(int CourseId);

/*Find Students counts in DB */
int SCounts();

/* Delete Student */
RETURN_STATUS DeleteS(int Sid);

/* Update Student */
RETURN_STATUS UpdateS(int Sid);

/*Show Students */
RETURN_STATUS ShowDB();

void DisplayStudent(struct SSinfo stud);

RETURN_STATUS StoreInFile(char *filename);

#endif