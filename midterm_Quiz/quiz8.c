#include <stdio.h>

void printrev(int *a, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int arr[] = {5, 6, 8, 9};
    printrev(arr, sizeof(arr) / sizeof(arr[0]));
}