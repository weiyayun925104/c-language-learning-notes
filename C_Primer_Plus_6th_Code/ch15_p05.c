#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

char * itobs (unsigned long, char *);
void show_bstr (const char *);
unsigned long rotate_l(unsigned long, unsigned long);

int main(int argc, char **argv)
{
    unsigned long val;
    unsigned long rot;
    unsigned long places;
    char bstr1[CHAR_BIT * sizeof (unsigned long) + 1];
    char bstr2[CHAR_BIT * sizeof (unsigned long) + 1];

    printf("Enter an integer (q to quit): ");
    while ( scanf("%lu", &val) == 1 )
    {
        printf("Enter the number of bits to be rotated: ");
        if ( scanf("%lu", &places) != 1 )
        {
            break;
        }
        rot = rotate_l(val, places);
        itobs(val, bstr1);
        show_bstr(bstr1);
        putchar ('\n');
        itobs(rot, bstr2);
        show_bstr(bstr2);
        putchar ('\n');
        printf("%lu rotated is %lu.\n", val, rot);
        printf("Enter an integer (q to quit): ");
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
unsigned long rotate_l(unsigned long n, unsigned long b)
{
    static const int size = CHAR_BIT * sizeof(unsigned long);

    b %= size;

    return ( (n << b) | ( n >> (size - b) ) );
}
