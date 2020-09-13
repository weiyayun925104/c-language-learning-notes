/* funds4.c -- 把结构数组传递给函数 */

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

double sum (const struct funds money[], int n);

int main(int argc, char **argv)
{
    struct funds jones[2] = 
    {
        {
            "Garlic-Melon Bank",
            "Lucky's Savings and Loan",
            4032.27,
            8543.94
        },
        {
            "Honest Jack's Bank",
            "Party Time Savings",
            3620.88,
            3802.91
        }
    };

    printf ("The Joneses have a total of $%.2f.\n", sum(jones, 2) );

    return 0;
}
double sum (const struct funds money[], int n)
{
    double total;
    int i;

    for (i = 0, total = 0.0; i < n; i++)
    {
        total += (money[i].bankfund + money[i].savefund);
    }

    return total;
}
