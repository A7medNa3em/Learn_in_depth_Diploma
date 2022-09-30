#include <stdio.h>

int addnum(int num)
{
    int sum = 0;

    while (num != 0)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d ", addnum(n));
}