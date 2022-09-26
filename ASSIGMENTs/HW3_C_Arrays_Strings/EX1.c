#include <stdio.h>

int main()
{
    float arr1[2][2];
    float arr2[2][2];

    printf("Enter elments of first matrix \n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("ar1[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &arr1[i][j]);
        }
    }

    printf("Enter elments of 2nd matrix \n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("ar2[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &arr2[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f  ", arr1[i][j] + arr2[i][j]);
        }

        printf("\r\n");
    }
    return 0;
}