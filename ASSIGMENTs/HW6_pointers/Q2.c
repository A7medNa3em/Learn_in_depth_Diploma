#include <stdio.h>

int main()
{
    char alphabet[27];

    char *ptr;

    ptr = alphabet;

    int i = 0;
    for (i = 0; i < 26; i++)
    {
        *ptr = i + 'A';
        ptr++;
    }

    ptr = alphabet;

    for (i = 0; i < 26; i++)
    {
        printf("%c ", *ptr);
        ptr++;
    }

    return 0;
}