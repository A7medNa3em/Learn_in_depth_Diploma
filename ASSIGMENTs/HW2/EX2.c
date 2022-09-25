#include <stdio.h>

int main()
{

    char ch;
    printf("Enter alphabet: ");
    scanf("%c", &ch);
    if ((((ch >= 'a') && (ch) <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
    {
        if ((ch == 'a') || (ch == 'i') || (ch == 'o') || (ch == 'e') || (ch == 'u'))
        {
            printf("%c is vowel \n", ch);
        }
        else
            printf("%c is consonant \n", ch);
    }

    return 0;
}