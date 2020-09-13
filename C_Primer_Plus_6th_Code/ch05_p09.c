#include <stdio.h>

void Temperatures(double Fahrenheit);

int main(void)
{
    double Fahrenheit;

    printf("Please enter a Fahrenheit temperature: ");
    while (scanf("%lf", &Fahrenheit) == 1)
    {
        Temperatures(Fahrenheit);
        printf("please enter the next Fahrenheit temperatures (q to quit): ");
    }
    printf("Done!\n");

    return 0;
}

void Temperatures(double Fahrenheit)
{
    const double Celsius = (5.0 / 9.0) * (Fahrenheit - 32.0);
    const double Kelvin = Celsius + 273.16;
    printf("The Fahrenheit temperature is %.2f.\n", Fahrenheit);
    printf("The Celsius temperature is %.2f.\n", Celsius);
    printf("The Kelvin temperature is %.2f.\n", Kelvin);
}
