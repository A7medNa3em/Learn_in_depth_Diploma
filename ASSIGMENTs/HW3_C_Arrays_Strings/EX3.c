#include <stdio.h>
#define MAX 20
int main()
{
    float arr1[MAX][MAX];
    float Tarr[MAX][MAX];
    int r, c;

    printf("Enter number of rows and columbs: ");
    scanf("%d", &r);
    scanf("%d", &c);

    printf("Enter elments of  matrix \n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("ar1[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &arr1[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            Tarr[j][i] = arr1[i][j];
        }
    }

    printf("Orginal Matrix\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.1f  ", arr1[i][j]);
        }

        printf("\r\n");
    }

    printf("Transpose Matrix\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%.1f  ", Tarr[i][j]);
        }

        printf("\r\n");
    }
    return 0;
}