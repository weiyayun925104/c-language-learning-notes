#include <stdio.h>

#define basic_pay_rate 10

#define basic_time 40
#define overtime 1.5

#define rate_tier_1 300
#define rate_tier_2 150

#define tax_rate_1 0.15
#define tax_rate_2 0.2
#define tax_rate_3 0.25

int main(int argc, char **argv)
{
    double hours, time;
    double gross_pay, taxes, net_pay;

    printf("How many hours your work in a week?\n");
    scanf("%lf", &hours);

    if (hours > basic_time)
    {
        time = ( basic_time + ( (hours - basic_time) * overtime) );
    }
    else
    {
        time = hours;
    }

    gross_pay = time * basic_pay_rate;

    if ( gross_pay < rate_tier_1 )
    {
        taxes = gross_pay * tax_rate_1;
    }
    else if ( gross_pay < (rate_tier_1 + rate_tier_2) )
    {
        taxes = rate_tier_1 * tax_rate_1 + (gross_pay - rate_tier_1) * tax_rate_2;
    }
    else
    {
        taxes = rate_tier_1 * tax_rate_1 + rate_tier_2 * tax_rate_2 + (gross_pay - rate_tier_1 - rate_tier_2) * tax_rate_3;
    }

    net_pay = gross_pay - taxes;

    printf("Your gross pay is $%g, your taxes is $%g, your net pay is $%g.\n", gross_pay, taxes, net_pay);

    return 0;
}

