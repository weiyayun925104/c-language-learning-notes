#include <stdio.h>

int main(int argc, char **argv)
{
    float miles, gallons, miles_per_gallon, liters_per_100km;
    const float liters_per_gallon = 3.785f;
    const float kilometers_per_mile = 1.609f;

    printf("Please enter the number of miles traveled:\n");
    scanf("%f", &miles);
    printf("Please enter the number of gallons of gasoline consumed:\n");
    scanf("%f", &gallons);

    miles_per_gallon = miles / gallons;
    printf("The value of miles-per-gallon is %.1f.\n", miles_per_gallon);

    liters_per_100km = 100.0f / (miles_per_gallon * (kilometers_per_mile / liters_per_gallon) );
    printf("The value of liters-per-100-km is %.1f.\n", liters_per_100km);

    return 0;
}
