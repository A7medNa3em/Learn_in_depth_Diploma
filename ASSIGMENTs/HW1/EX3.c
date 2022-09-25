#include <stdio.h>

int main()
{
    int i, j;
    printf("Enter two number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d%d", &i, &j);
    printf("You Entered: %d \n", i + j);
}