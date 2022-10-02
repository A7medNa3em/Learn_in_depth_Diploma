#include <stdio.h>

struct Sdistentance
{
    int foot;
    float inch;
};

struct Sdistentance sumDistance(struct Sdistentance *d1, struct Sdistentance *s2);
int main()
{
    struct Sdistentance sumD;
    struct Sdistentance D1;
    struct Sdistentance D2;

    printf("Enter Distance 1 data \n");
    printf("\tEnter feet ");
    scanf("%d", &D1.foot);
    fflush(stdin);
    printf("\tEnter inches ");
    scanf("%f", &D1.inch);
    fflush(stdin);

    printf("Enter Distance 2 data \n");
    printf("\tEnter feet ");
    scanf("%d", &D2.foot);
    fflush(stdin);
    printf("\tEnter inches ");
    scanf("%f", &D2.inch);
    fflush(stdin);

    sumD = sumDistance(&D1, &D2);

    printf("Sum of distance : %d\'-%.2f\" \n ", sumD.foot, sumD.inch);

    return 0;
}

struct Sdistentance sumDistance(struct Sdistentance *d1, struct Sdistentance *d2)
{
    struct Sdistentance sum;

    sum.foot = d1->foot + d2->foot;
    sum.inch = d1->inch + d2->inch;

    if (sum.inch >= 12)
    {
        sum.foot++;
        sum.inch -= 12;
    }

    return sum;
}
