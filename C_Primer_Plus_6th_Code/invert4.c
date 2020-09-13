/* invert4.c -- 使用位操作显示二进制 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

char * itobs (unsigned long, char *);
void show_bstr (const char *);
unsigned long invert_end (unsigned long num, int bits);

int main(int argc, char **argv)
{
    char bin_str[ CHAR_BIT * sizeof(unsigned long) + 1] = {0};
    unsigned long number;

    printf ("Enter an integer (q to quit) : \n");
    while ( scanf ("%lu", &number) == 1)
    {
        printf ("Binary equivalent:\n");
        itobs (number, bin_str);
        show_bstr(bin_str);
        putchar ('\n');
        number = invert_end (number, 4);
        printf ("Inverting the last 4 bits gives\n");
        itobs (number, bin_str);
        show_bstr(bin_str);
        putchar ('\n');
        printf ("Enter an integer (q to quit) : \n");
    }
    printf ("Done.\n");

    return 0;
}
char * itobs (unsigned long n, char * ps)
{
    int i;
    static const int size = CHAR_BIT * sizeof (unsigned long);

    for (i = size - 1; i >=0; i--, n>>=1)
    {
        ps[i] = ( 1UL & n) + '0';
    }
    ps[size] = '\0';

    return ps;
}
void show_bstr (const char * str)
{
    int i= 0;

    while ( str[i] )
    {
        putchar ( str[i] );
        if (i % 4 == 3 && str[i+1] )
        {
            putchar (' ');
        }
        i++;
    }
}
unsigned long invert_end (unsigned long num, int bits)
{
    unsigned long mask = 0UL;
    unsigned long bitval = 1UL;

    while (bits > 0)
    {
        mask |= bitval;
        bitval <<= 1;
        bits--;
    }

    return (num ^ mask);
}
