#include <stdio.h>

int main(void)
{
    double amount_quarts, amount_grams, amount_molecules;

    printf("Please enter an amount of water in quarts: ");
    scanf("%lf", &amount_quarts);
    amount_grams = (950 * amount_quarts);
    amount_molecules = amount_grams / 3.0e-23;
    printf("The number of water molecules in %f quarts is %e molecules.\n", amount_quarts, amount_molecules);

    return 0;
}
