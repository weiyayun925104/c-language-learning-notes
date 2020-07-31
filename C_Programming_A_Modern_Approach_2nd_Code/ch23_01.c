#include <stdio.h>
#include <math.h>

double round_nearest(double x, int n)
{
    int power = pow(10, n);
    return x < 0.0 ? ceil(x * power - 0.5) / power : floor(x * power + 0.5) / power;
}

int main(int argc, char **argv)
{
    printf("%lf\n", round_nearest(3.14159, 3) );
    return 0;
}
