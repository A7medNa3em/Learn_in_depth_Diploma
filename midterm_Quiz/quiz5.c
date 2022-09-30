#include <stdio.h>

int getones(int num)
{
    int i = 0;

    while (num != 0)
    {
        if (num % 2)
            i++;
        num /= 2;
    }

    return i;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d", getones(n));
}