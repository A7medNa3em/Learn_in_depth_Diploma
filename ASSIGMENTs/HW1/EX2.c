#include <stdio.h>

int main()
{
    int i;
    printf("Enter number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &i);
    printf("You Entered: %d \n", i);
}