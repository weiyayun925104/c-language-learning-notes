/* funds3.c -- 传递一个结构 */

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

double sum (struct funds moolah);

int main(int argc, char **argv)
{
    struct funds stan = 
    {
        "Garlic-Melon Bank", 
        "Lucky's Savings and Loan", 
        4032.27, 
        8543.94
    };

    printf ("Stan has a total of $%.2f.\n", sum (stan) );

    return 0;
}
double sum (struct funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}
