#include <stdio.h>

void unqarr(int *a, int len)
{
    int unqflag = 1;

    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < len; i++)
        {
            if (i == j)
                continue;
            if (a[j] == a[i])
            {
                unqflag = 0;
                break;
            }
            else
            {
                unqflag = 1;
            }
        }

        if (1 == unqflag)
            printf("%d ", a[j]);
    }
}

int main()
{
    int arr[] = {5, 6, 7, 5, 6};

    unqarr(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}