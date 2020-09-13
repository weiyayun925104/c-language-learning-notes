#include <stdio.h>
#include <float.h>

int main(int argc, char **argv)
{
    double nd = 1.0 / 3.0;
    float fd = 1.0f / 3.0f;

    printf("double values: ");
    printf("%.6f %.12f %.16f\n", nd, nd, nd);
    printf("float values: ");
    printf("%.6f %.12f %.16f\n", fd, fd, fd);

    printf("\n");

    printf("float precision = %d digits\n", FLT_DIG);
    printf("double precision = %d digits\n", DBL_DIG);

    return 0;
}
