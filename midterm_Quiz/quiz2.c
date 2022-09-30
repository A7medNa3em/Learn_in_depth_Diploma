#include <stdio.h>
#include <math.h>

double root(double num)
{
    return sqrt(num);
}

int main()
{
    double n;
    printf("Enter number: ");
    scanf("%lf", &n);
    printf("%.3f", root(n));
}