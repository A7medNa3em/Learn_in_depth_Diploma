#include <stdio.h>

void PrimeNumbers(int x1, int x2);

int main()
{
    int i1, i2;
    printf("Enter interval ");
    scanf("%d", &i1);
    scanf("%d", &i2);
    printf("prime numbers between %d and %d: ", i1, i2);
    PrimeNumbers(i1, i2);
    return 0;
}

void PrimeNumbers(int x1, int x2)
{
    int i = 2;
    int primeflag = 0;
    for (; x1 <= x2; x1++)
    {
        for (i = 2; i < 10; i++)
        {
            if (x1 % i == 0)
            {
                primeflag = 0;
                break;
            }
            else
                primeflag = 1;
        }

        if (primeflag == 1)
        {
            printf("%d  ", x1);
        }
    }
}