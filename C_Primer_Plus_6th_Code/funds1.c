/* funds1.c -- 把结构成员作为参数传递 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct funds
{
    char bank[STRLEN];
    char save[STRLEN];
    double bankfund;
    double savefund;
};

double sum (double, double);

int main(int argc, char **argv)
{
    struct funds stan = 
    {
        "Garlic-Melon Bank", 
        "Lucky's Savings and Loan", 
        4032.27, 
        8543.94
    };

    printf ("Stan has a total of $%.2f.\n", sum (stan.bankfund, stan.savefund) );

    return 0;
}
double sum (double x, double y)
{
    return (x + y);
}
