#include <stdio.h>
#define MAX 20
int main()
{
    float arr1[MAX], sum = 0;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("arr[%d]: ", i + 1);
        scanf("%f", &arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr1[i];
    }

    printf("Average is  %.2f \n", sum / n);

    return 0;
}