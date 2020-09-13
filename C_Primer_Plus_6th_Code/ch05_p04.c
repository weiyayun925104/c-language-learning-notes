#include <stdio.h>

int main(int argc, char **argv)
{
    const float cmpf = 30.48;   // centimeters_per_foot
    const float cmpi = 2.54;   // centimeters_per_inch
    float cm;
    int feet;
    float inches;

    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    while (cm > 0.0f)
    {
        feet = cm / cmpf;
        inches = (cm - feet * cmpf) / cmpi;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inches);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &cm);
    }
    printf("Done!\n");

    return 0;
}
