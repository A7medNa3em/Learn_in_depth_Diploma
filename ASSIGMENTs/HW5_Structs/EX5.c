#include <stdio.h>

#define PI 3.14

#define CircleArea(reduis) (PI * reduis * reduis)

int main()
{
    int r;
    printf("Enter Reduis ");
    scanf("%d", &r);

    printf("Circle Area : %.2f \n", CircleArea(r));

    return 0;
}