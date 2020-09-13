#include <stdio.h>

int main(int argc, char **argv)
{
    double cups, pints, ounces, tablespoons, teaspoons;

    printf("Please enter a volume in cups: ");
    scanf("%lf", &cups);

    pints = cups / 2;
    ounces = cups * 8;
    tablespoons = ounces * 2;
    teaspoons = tablespoons * 3;

    printf("%.2f cups equal %.2f pints.\n", cups, pints);
    printf("%.2f cups equal %.2f ounces.\n", cups, ounces);
    printf("%.2f cups equal %.2f tablespoons.\n", cups, tablespoons);
    printf("%.2f cups equal %.2f teaspoons.\n", cups, teaspoons);

    return 0;
}
