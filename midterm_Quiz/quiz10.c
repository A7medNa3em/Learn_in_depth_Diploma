#include <stdio.h>

int getones(int num)
{
    int i = 0;
    int bin[32] = {0};
    int r;
    int max = 0, max1 = 0;

    while (num != 0)
    {
        r = num % 2;

        bin[i] = r;

        num /= 2;
        i++;
    }
    for (int j = 0; j < 32; j++)
    {
        if (bin[j] == 0)
        {
            max1 = 0;
            for (int k = j + 1; bin[k] == 1; k++)
            {
                max1++;
                i++;
            }
        }

        if (max1 > max)
            max = max1;
    }
    return max;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("\n%d ", getones(n));

    return 0;
}