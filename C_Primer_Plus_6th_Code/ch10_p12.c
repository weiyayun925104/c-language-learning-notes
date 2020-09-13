#include <stdio.h>

#define MONTHS 12
#define YEARS 5

void func_rain_year(const double array[][MONTHS], int years);
void func_rain_month(const double array[][MONTHS], int years);

int main(int argc, char **argv)
{
    const double rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    func_rain_year(rain, YEARS);
    func_rain_month(rain, YEARS);

    return 0;
}

void func_rain_year(const double array[][MONTHS], int years)
{
    int year, month;
    double subtotal, total;

    printf ("YEAR         RAINFALL    (inches)\n");
    for (year = 0, total = 0.0; year < years; year++)
    {
        for (month = 0, subtotal = 0.0; month < MONTHS; month++)
        {
            subtotal += *(*(array + year) + month);
        }
        printf ("%5d %15.2f\n", 2010 + year, subtotal);
        total += subtotal;
    }
    printf ("\nThe yearly average is %.2f inches.\n\n", (total / years) );
}
void func_rain_month(const double array[][MONTHS], int years)
{
    int year, month;
    double subtotal;

    printf ("MONTHLY         AVERAGES: \n\n");
    printf ("   Jan   Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct   Nov   Dec\n");
    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtotal = 0.0; year < years; year++)
        {
            subtotal += *(*(array + year) + month);
        }
        printf ("%6.2f ", (subtotal / years) );
    }
    printf ("\n");
}
