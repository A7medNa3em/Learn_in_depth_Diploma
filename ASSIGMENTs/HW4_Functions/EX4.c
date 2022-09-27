#include <stdio.h>

int POWf(int num, int p);

int main()
{
    int n, p;
    printf("Enter number and power ");
    scanf("%d", &n);
    scanf("%d", &p);

    printf(" %d^%d = %d\n", n, p, POWf(n, p));

    return 0;
}

int POWf(int num, int p)
{
    int f = num;

    if (p > 1)
    {
        p--;
        f = f * POWf(num, p);
    }

    return f;
}
