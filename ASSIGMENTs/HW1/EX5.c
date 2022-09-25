#include <stdio.h>

int main()
{
    char i;
    printf("Enter character : ");
    fflush(stdin);
    fflush(stdout);
    scanf("%c", &i);
    printf("ASCII Number of %C: %d \n", i, i);
}