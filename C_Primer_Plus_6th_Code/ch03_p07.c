#include <stdio.h>

int main(void)
{
    double height_centimeters, height_inches;
    double centimeters_to_inch = 2.54;

    printf("Please enter your height in inches: ");
    scanf("%lf", &height_inches);
    height_centimeters = (height_inches * centimeters_to_inch);
    printf("Your height in centimeters is %f\n", height_centimeters);

    return 0;
}
