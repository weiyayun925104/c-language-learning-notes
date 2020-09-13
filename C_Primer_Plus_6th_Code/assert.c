/* assert.c -- Ê¹ÓÃassert */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main(int argc, char **argv)
{
    double x, y, z;

    puts ("Enter a pair of numbers (q to quit) :");
    while ( scanf ("%lf %lf", &x, &y) == 2 && (x != 0.0 || y != 0.0) )
    {
        z = (x * x) - (y * y);
        assert (z >= 0.0);
        printf ("sqrt(%g) = %g\n", z, sqrt(z) );
        puts ("Enter a pair of numbers (q to quit) :");
    }
    printf ("Done.\n");

    return 0;
}
