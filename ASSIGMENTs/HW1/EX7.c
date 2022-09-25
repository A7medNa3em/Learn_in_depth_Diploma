#include <stdio.h>

int main()
{
    int i, j;
    printf("Enter value of i: ");
    scanf("%d", &i);
    printf("Enter value of j: ");
    scanf("%d", &j);
    /* add sub method*/
    // i = i + j;
    // j = i - j;
    // i = i - j;

    /* Xor method*/
    i = i ^ j;
    j = i ^ j;
    i = i ^ j;

    printf("After swap value of i: %d \n", i);
    printf("After swap value of j: %d \n", j);
}