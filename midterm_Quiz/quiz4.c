#include <stdio.h>

void revnum(int num)
{
    int i = 0;

    while (num != 0)
    {
        i = num % 10;
        num /= 10;

        printf("%d", i);
    }
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    revnum(n);
}