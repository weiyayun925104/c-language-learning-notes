#include <stdio.h>

int main(int argc, char **argv)
{
    double x, y;
    printf ("Enter inch: ");
    scanf ("%lf", &x);
    y = (x * 2.54);
    printf ("%g inch = %g cm\n", x, y );
    return 0;
}
