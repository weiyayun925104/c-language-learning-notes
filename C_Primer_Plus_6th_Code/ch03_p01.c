#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv)
{
    printf("Maximum int value on this system = %d\n", INT_MAX);
    printf("Maximum float value on this system = %e\n", FLT_MAX);
    printf("Minimum float value on this system = %e\n", FLT_MIN);
    printf("Integer overflow: %d + 1 = %d\n", INT_MAX, INT_MAX + 1);
    printf("Floating-point overflow: %e * 10 = %e\n", FLT_MAX, FLT_MAX * 10);
    printf("Floating-point underflow: %e / 10 = %e\n", FLT_MIN, FLT_MIN / 10);

    return 0;
}
