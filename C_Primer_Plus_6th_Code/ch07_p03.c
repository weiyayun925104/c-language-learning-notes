#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    double sum_even = 0.0, sum_odd = 0.0;
    int count_even = 0, count_odd = 0;
    double average_even, average_odd;

    printf("Please enter your numbers: ");
    while ( scanf("%d", &i) == 1 && i != 0)
    {
        if (i % 2 == 0)
        {
            sum_even += i;
            count_even++;
        }
        else
        {
            sum_odd += i;
            count_odd++;
        }
    }


    printf("The number of evens: %d\n", count_even);
    if (count_even > 0)
    {
        average_even = sum_even / count_even;
        printf("The average value of evens: %g\n", average_even);
    }
    printf("The number of odds: %d\n", count_odd);
    if (count_odd > 0)
    {
        average_odd = sum_odd / count_odd;
        printf("The average value of odds: %g\n", average_odd);
    }

    return 0;
}
