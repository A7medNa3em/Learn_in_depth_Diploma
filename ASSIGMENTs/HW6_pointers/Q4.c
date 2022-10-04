#include <stdio.h>

int main()
{
    int arr[15];
    int n;

    int *ptr = arr;

    printf("Enter number of aray elenebts : ");
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("Element [%d]: ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }
    ptr = arr + n - 1;

    printf("Elements in reverse direction \n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("Element [%d]: %d \n", i + 1, *ptr);
        ptr--;
    }

    return 0;
}