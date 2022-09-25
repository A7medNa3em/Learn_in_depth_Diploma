#include <stdio.h>

int main()
{
    float i, j;
    printf("Enter two number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f%f", &i, &j);
    printf("You Entered: %f \n", i * j);
}