#include <stdio.h>

float get_tax(float income);

int main(int argc, char **argv)
{
    float income;

    printf("Enter taxable income: ");
    scanf("%f", &income);

    printf("Tax due: $%.2f\n", get_tax(income));

    return 0;
}

float get_tax(float income)
{
    float tax;

    if (income <= 750.00f)
    {
        tax = 0.01f * income;
    }
    else if (income <= 2250.00f)
    {
        tax = 7.50f + (0.02f * (income - 750.00f));
    }
    else if (income <= 3750.00f)
    {
        tax = 37.50f + (0.03f * (income - 2250.00f));
    }
    else if (income <= 5250.00f)
    {
        tax = 82.50f + (0.04f * (income - 3750.00f));
    }
    else if (income <= 7000)
    {
        tax = 142.50f + (0.05f * (income - 5250.00f));
    }
    else
    {
        tax = 230.00f + (0.06f * (income - 7000.00f));
    }

    return tax;
}
