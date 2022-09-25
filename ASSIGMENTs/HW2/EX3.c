#include <stdio.h>

int main()
{

    float num1, num2, num3, bigger;
    printf("Enter 3 numbers: ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);
    bigger = (num1 >= num2 ? num1 : num2) < num3 ? num3 : (num1 >= num2 ? num1 : num2);
    printf("biggest is : %f ", bigger);

    return 0;
}