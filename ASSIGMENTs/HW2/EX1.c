#include <stdio.h>

int main()
{

    int num;
    printf("Enter Numbner: ");
    scanf("%d", &num);

    // if (num % 2 == 0)
    // {
    //     printf("%d is even \n", num);
    // }
    // else
    //     printf("%d is odd \n", num);

    (num % 2 == 0) ? printf("%d is even \n", num) : printf("%d is odd \n", num);

    return 0;
}