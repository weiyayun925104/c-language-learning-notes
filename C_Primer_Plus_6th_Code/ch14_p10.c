#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define NUM 4

double twice(double x);
double half(double x);
double thrice(double x);

void showmenu(void);

int main(int argc, char **argv)
{
    double (* arpf[NUM] ) (double) = {twice, half, thrice, sqrt};
    double val;
    double ans;
    int sel;

    printf("Enter a number (negative to quit): ");
    while ( scanf("%lf", &val) == 1 && val >= 0.0 )
    {
        while (getchar() != '\n')
        {
            continue;
        }
        showmenu();
        while ( scanf("%d", &sel) == 1 && sel >= 0 && sel <= 3)
        {
            while (getchar() != '\n')
            {
                continue;
            }
            ans = (* (arpf[sel]) )(val);
            printf("1 answer = %f\n", ans);
            ans = arpf[sel](val);
            printf("one answer = %f\n", ans);
            showmenu();
        }
        printf("Enter a number (negative to quit): ");
    }
    printf ("Done.\n");

    return 0;
}
void showmenu(void)
{
    puts("Enter one of the following choices:");
    puts("0) double the value        1) halve the value");
    puts("2) triple the value        3) squareroot the value");
    puts("4) next number");
}

double twice(double x) {return 2.0 * x;}
double half(double x) {return x / 2.0;}
double thrice(double x) {return 3.0 * x;}
