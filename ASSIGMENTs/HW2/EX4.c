#include <stdio.h>

int main()
{

    int num;
    printf("Enter Numbner: ");
    scanf("%d", &num);

    (num >= 0) ? printf("%d is postive \n", num) : printf("%d is negative \n", num);

    return 0;
}