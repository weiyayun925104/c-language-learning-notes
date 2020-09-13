#include <stdio.h>

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
    double basic_pay_rate;
    double gross_pay, taxes, net_pay;
    char choice;

begin:
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                         2) $9.33/hr\n");
    printf("3) $10.00/hr                        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");

a:
    while ( ( choice = getchar() ) == '\n' )
    {
        continue;
    }
    while (getchar() != '\n')
    {
        continue;
    }

    switch (choice)
    {
    case '1':
        basic_pay_rate = 8.75;
        break;
    case '2':
        basic_pay_rate = 9.33;
        break;
    case '3':
        basic_pay_rate = 10.00;
        break;
    case '4':
        basic_pay_rate = 11.20;
        break;
    case '5':
        printf("Done!\n");
        return 0;
        break;
    default :
        printf("\nPlease enter 1~5 to choose a pay rate or action:\n");
        printf("1) $8.75/hr                         2) $9.33/hr\n");
        printf("3) $10.00/hr                        4) $11.20/hr\n");
        printf("5) quit\n");
        goto a;
        break;
    }

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

    goto begin;

    return 0;
}
