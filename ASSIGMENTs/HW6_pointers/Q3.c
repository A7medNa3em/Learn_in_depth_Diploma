#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[50];

    printf("Enter sentence: ");
    gets(sentence);
    // printf("%s", sentence);
    char *ptr = sentence + strlen(sentence) - 1;

    int i = 0;
    for (i = strlen(sentence) - 1; i >= 0; i--)
    {
        printf("%c", *ptr);
        ptr--;
    }

    return 0;
}