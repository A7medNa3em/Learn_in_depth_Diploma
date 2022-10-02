#include <stdio.h>

struct Srealnumber
{
    float Re;
    float Im;
};

struct Srealnumber sumReal(struct Srealnumber *n1, struct Srealnumber *n2);
int main()
{
    struct Srealnumber sumN;
    struct Srealnumber N1;
    struct Srealnumber N2;

    printf("Enter 1st Number \n");
    printf("\tEnter real part ");
    scanf("%f", &N1.Re);
    fflush(stdin);
    printf("\tEnter imaginary part ");
    scanf("%f", &N1.Im);
    fflush(stdin);

    printf("Enter 2nd Number  data \n");
    printf("\tEnter real part ");
    scanf("%f", &N2.Re);
    fflush(stdin);
    printf("\tEnter imaginary part ");
    scanf("%f", &N2.Im);
    fflush(stdin);

    sumN = sumReal(&N1, &N2);

    printf("Sum of Numbers : %.2f + i%.2f \n ", sumN.Re, sumN.Im);

    return 0;
}

struct Srealnumber sumReal(struct Srealnumber *N1, struct Srealnumber *N2)
{
    struct Srealnumber sum;

    sum.Re = N1->Re + N2->Re;
    sum.Im = N1->Im + N2->Im;

    return sum;
}
