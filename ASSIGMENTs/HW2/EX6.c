#include <stdio.h>

int main()
{

    int num;
    int i = 0;
    int sum = 0;

    printf("Enter Numbner: ");
    scanf("%d", &num);

    /* Method 1 loop*/
    for (i = 1; i <= num; i++)
    {
        sum += i;
    }
    printf("Method 1 :Sum = %d \n", sum);

    /* Method 2 numerical */

    printf("Method 2 :Sum = %d \n", (num + 1) * num / 2);
    return 0;
}