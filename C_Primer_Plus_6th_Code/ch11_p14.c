#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    double num, exp;

    if (argc != 3)
    {
        printf("Usage: %s number exponent\n", argv[0]);
    }
    else
    {
        num = strtod(argv[1], NULL);
        exp = strtod(argv[2], NULL);
        printf("%f to the %f power = %g\n", num, exp, pow(num, exp));
    }

    return 0;
}
