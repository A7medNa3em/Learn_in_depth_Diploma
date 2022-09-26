#include <stdio.h>

int main()
{
    char str[50];
    char i = 1;

    printf("Enter string: ");
    gets(str);

    while (str[i] != '\0')
    {
        i++;
    }

    printf("The length of string is %d ", i);

    return 0;
}