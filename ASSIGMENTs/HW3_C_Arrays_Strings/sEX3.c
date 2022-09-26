#include <stdio.h>

int main()
{
    char str[50], Rstr[50];
    char i = 0, k = 0;

    printf("Enter string: ");
    gets(str);

    while (str[i] != '\0')
    {
        i++;
    }

    for (int j = i - 1, k = 0; j >= 0; j--, k++)
    {
        Rstr[k] = str[j];
    }
    Rstr[i] = '\0';

    printf("Reversing string: %s", Rstr);

    return 0;
}