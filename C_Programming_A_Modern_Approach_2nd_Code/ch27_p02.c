#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(int argc, char **argv)
{
    double real, imag, r, theta;

    printf("Enter real value of complex number: ");
    scanf("%lf", &real);
    printf("Enter imaginary value of complex number: ");
    scanf("%lf", &imag);

    r = sqrt(real * real + imag * imag);
    theta = atan(imag / real);

    printf("r = %g\ntheta = %g rads\n", r, theta);
    return 0;
}
