#include <stdio.h>

int main()
{
    char str[50];
    char ch, freq = 0, i = 0;

    printf("Enter string: ");
    gets(str);

    printf("Enter number to find frequency: ");
    scanf("%c", &ch);

    while (str[i] != '\0')
    {
        if (str[i] == ch)
            freq++;

        i++;
    }

    printf("Frequency of '%c' is %d ", ch, freq);

    return 0;
}