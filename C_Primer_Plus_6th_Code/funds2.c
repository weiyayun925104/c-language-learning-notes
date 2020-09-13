/* funds2.c -- 传递指向结构的指针 */

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

double sum (const struct funds * money);

int main(int argc, char **argv)
{
    struct funds stan = 
    {
        "Garlic-Melon Bank", 
        "Lucky's Savings and Loan", 
        4032.27, 
        8543.94
    };

    printf ("Stan has a total of $%.2f.\n", sum (&stan) );

    return 0;
}
double sum (const struct funds * money)
{
    return (money->bankfund + money->savefund);
}
