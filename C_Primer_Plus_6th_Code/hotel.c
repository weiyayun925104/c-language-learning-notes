/* hotel.c -- ¾Æµê¹ÜÀíº¯Êý */

#include <stdio.h>
#include "hotel.h"

int menu (void)
{
    int code, status;
    int input;

    printf ("\n%s%s\n", STARS, STARS);
    printf ("Enter the number of the desired hotel: \n");
    printf ("1) Fairfield Arms           2) Hotel Olympic\n");
    printf ("3) Chertworthy Plaza    4) The Stockton\n");
    printf ("5) quit\n");
    printf ("%s%s\n", STARS, STARS);

    while ( ( status = scanf ("%d", &code) ) != 1 || (code < 1 || code > 5) )
    {
        if (status != 1)
        {
            while ( ( input = getchar() ) != '\n' )
            {
                putchar(input);
            }
            printf(" is not an integer.\n");
            printf("Please enter an integer: ");
        }
        else
        {
            while ( getchar() != '\n' )
            {
                continue;
            }
            printf("Please enter an integer from 1 to 5: ");
        }
    }
    while ( getchar() != '\n' )
    {
        continue;
    }

    return code;
}
int getnights (void)
{
    int nights, status;
    int input;


    printf ("How many nights are needed? ");

    while ( ( status = scanf ("%d", &nights) ) != 1 || (nights < 1 || nights > 365) )
    {
        if (status != 1)
        {
            while ( ( input = getchar() ) != '\n' )
            {
                putchar(input);
            }
            printf(" is not an integer.\n");
            printf("Please enter an integer: ");
        }
        else
        {
            while ( getchar() != '\n' )
            {
                continue;
            }
            printf("Please enter an integer from 1 to 365: ");
        }
    }
    while ( getchar() != '\n' )
    {
        continue;
    }

    return nights;
}
void showprice (double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
    {
        total += (rate * factor);
    }
    printf ("The total cost will be $%.2f.\n", total);
}
