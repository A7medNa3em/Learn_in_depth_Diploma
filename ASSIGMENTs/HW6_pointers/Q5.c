#include <stdio.h>

struct Semp
{
    char name[20];
    int ID;
};

int main()
{
    struct Semp e1 = {"ahmed", 22};
    struct Semp e2 = {"Omar", 33};
    struct Semp *(*ptr)[2];

    struct Semp *arre[2] = {&e1, &e2};

    ptr = &arre;

    printf("Employee 1 name : %s \n", (*ptr[0])->name);
    printf("Employee 1 ID   : %d \n", (*ptr[0])->ID);
    printf("Employee 2 name : %s \n", (*ptr[1])->name);
    printf("Employee 2 ID   : %d \n", (*ptr[2])->ID);

    return 0;
}