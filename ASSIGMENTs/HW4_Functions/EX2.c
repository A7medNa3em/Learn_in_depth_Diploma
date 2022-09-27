#include <stdio.h>

int fact(int num);

int main()
{
    int n;
    printf("Enter number ");
    scanf("%d", &n);

    printf("factorial of %d is %d \n", n, fact(n));

    return 0;
}

int fact(int num)
{
    int f = num;

    if (num > 1)
    {
        num--;
        f = f * fact(num);
    }

    return f;
}
