#include <stdio.h>

int main()
{

    char ch;
    printf("Enter alphabet: ");
    scanf("%c", &ch);
    if ((((ch >= 'a') && (ch) <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
    {

        printf("%c is Alphabet \n", ch);
    }
    else
        printf("%c is not Alphabet \n", ch);
    return 0;
}