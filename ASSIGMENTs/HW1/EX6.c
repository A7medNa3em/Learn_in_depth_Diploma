#include <stdio.h>

int main()
{
    int i, j, temp;
    printf("Enter value of i: ");
    scanf("%d", &i);
    printf("Enter value of j: ");
    scanf("%d", &j);

    temp = i;
    i = j;
    j = temp;

    printf("After swap value of i: %d \n", i);
    printf("After swap value of j: %d \n", j);
}