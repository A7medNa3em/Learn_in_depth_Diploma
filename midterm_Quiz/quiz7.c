#include <stdio.h>

int sumn(int num)
{

    return ((num + 1) * (num / 2));
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d", sumn(n));
}