#include <stdio.h>
#include <string.h>

void RevStr(char *s, char *s2, int len);

int main()
{
    char str[30], Rstr[30];
    printf("Enter sentence: ");
    gets(str);

    RevStr(str, Rstr, strlen(str));

    printf("Reversed : %s", Rstr);

    return 0;
}

void RevStr(char *s, char *s2, int len)
{
    int i = strlen(s) - len;
    len--;
    s2[i] = s[len];
    if (len > 0)
    {
        RevStr(s, s2, len);
    }
    else if (len == 0)
    {
        s2[i] = '\0';
    }
}
