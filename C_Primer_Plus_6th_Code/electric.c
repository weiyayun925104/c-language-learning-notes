// electric.c -- º∆À„µÁ∑—

#include <stdio.h>

#define RATE1 0.13230
#define RATE2 0.15040
#define RATE3 0.30025
#define RATE4 0.34025

#define BREAK1 360.0
#define BREAK2 468.0
#define BREAK3 720.0

#define BASE1 (RATE1 * BREAK1)
#define BASE2 ( (RATE1 * BREAK1) + (RATE2 * (BREAK2 - BREAK1) ) )
#define BASE3 ( (RATE1 * BREAK1) + (RATE2 * (BREAK2 - BREAK1) ) + (RATE3 * (BREAK3 - BREAK2) ) )

int main(int argc, char **argv)
{
    double kwh;
    double bill;

    printf ("Please enter the kwh used.\n");
    scanf ("%lf", &kwh);
    if (kwh <= BREAK1)
    {
        bill = (RATE1 * kwh);
    }
    else if (kwh <= BREAK2)
    {
        bill = ( (RATE1 * BREAK1) + (RATE2 * (kwh - BREAK1) ) );
    }
    else if (kwh <= BREAK3)
    {
        bill = ( (RATE1 * BREAK1) + (RATE2 * (BREAK2 - BREAK1) ) + (RATE3 * (kwh - BREAK2) ) );
    }
    else
    {
        bill = ( (RATE1 * BREAK1) + (RATE2 * (BREAK2 - BREAK1) ) + (RATE3 * (BREAK3 - BREAK2) )  + (RATE4 * (kwh - BREAK3) ) );
    }
    printf ("The charge for %.2f kwh is $%.2f.\n", kwh, bill);

    return 0;
}
