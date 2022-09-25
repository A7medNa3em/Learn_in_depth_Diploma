#include <stdio.h>

int main()
{

    int num;
    int fact = 1;
    int i;
    printf("Enter alphabet: ");
    scanf("%d", &num);
    if (num > 0)
    {
        for (i = 1; i <= num; i++)
        {
            fact *= i;
        }

        printf("factorial of %d is %d \n", num, fact);
    }
    else
        printf("ERROR factorial of negative is not exist \n");

    return 0;
}
