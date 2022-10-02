#include <stdio.h>

struct Sstudent
{
    char name[15];
    int roll;
    float marks;
};

int main()
{

    struct Sstudent student;

    printf("Enter student data \n");
    printf("Enter Name ");
    gets(student.name);
    fflush(stdin);
    printf("Enter Roll number ");
    scanf("%d", &student.roll);
    fflush(stdin);
    printf("Enter marks ");
    fflush(stdin);
    scanf("%f", &student.marks);

    printf("Display student data \n");
    printf("Name %s\n", student.name);
    printf("Roll number %d\n", student.roll);
    printf("Marks %.2f\n", student.marks);

    return 0;
}