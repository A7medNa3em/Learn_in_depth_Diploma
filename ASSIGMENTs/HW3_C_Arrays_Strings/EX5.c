#include <stdio.h>
#define MAX 20
int main()
{
    float arr1[MAX], num;
    int flag = 0, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("arr[%d]: ", i + 1);
        scanf("%f", &arr1[i]);
    }

    printf("\nEnter number to search : ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f", &num);

    for (int i = 0; i < n; i++)
    {
        if (arr1[i] == num)
        {
            printf(" %.1f is found in postion %d \n", num, i + 1);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf(" %.1f is not found \n", num);
    }

    return 0;
}