#include <stdio.h>
#define MAX 20
int main()
{
    float arr1[MAX], arr2[MAX], num;
    int n, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("arr[%d]: ", i + 1);
        scanf("%f", &arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %.1f ", arr1[i]);
    }

    printf("\nEnter number to add: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f", &num);
    printf("Enter postion: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &pos);

    for (int i = 0; i < n + 1; i++)
    {
        if (i < pos)
            arr2[i] = arr1[i];
        else if (i == pos)
        {
            arr2[i] = num;
        }

        else
        {
            arr2[i] = arr1[i - 1];
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        printf(" %.1f ", arr2[i]);
    }

    return 0;
}