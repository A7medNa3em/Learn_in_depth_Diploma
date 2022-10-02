#include <stdio.h>

struct Sstudent
{
    char name[15];
    int roll;
    float marks;
};

int main()
{

    struct Sstudent students[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter student (%d) data \n", i + 1);
        printf("\tEnter Name ");
        fflush(stdin);
        gets(students[i].name);
        printf("\tEnter Roll number ");
        fflush(stdin);
        scanf("%d", &students[i].roll);
        printf("\tEnter marks ");
        fflush(stdin);
        scanf("%f", &students[i].marks);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n student (%d) \n", i + 1);
        printf("\tName: %s\t", students[i].name);
        printf("\tRoll number: %d\t", students[i].roll);
        printf("\tMarks: %.2f\t", students[i].marks);
    }

    return 0;
}