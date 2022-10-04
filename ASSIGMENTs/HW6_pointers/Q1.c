#include <stdio.h>

int main()
{
    int m = 29;

    // Address of m : 0x7ffcc3ad291c
    // Value of m : 29
    printf("Address of m:   %p, m = %d \n", &m, m);

    // Now ab is assigned with the address of m.
    int *ab = &m;
    // Address of pointer ab : 0x7ffcc3ad291c
    // Content of pointer ab : 29
    printf("Address of ab:  %p, ab = %d \n", ab, *ab);

    // The value of m assigned to 34 now.
    m = 34;
    // Address of pointer ab : 0x7ffcc3ad291c
    // Content of pointer ab : 34
    printf("Address of ab:  %p, ab = %d \n", ab, *ab);

    // The pointer variable ab is assigned with the
    *ab = 7;
    // value 7 now.
    // Address of m : 0x7ffcc3ad291c
    // Value of m : 7
    printf("Address of m:   %p, m = %d \n", &m, m);

    return 0;
}