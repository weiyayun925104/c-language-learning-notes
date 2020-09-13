#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

char * itobs (unsigned long, char *);
void show_bstr (const char *);
int onbits(unsigned long);

int main(int argc, char **argv)
{
    unsigned long val;
    char bstr[CHAR_BIT * sizeof(unsigned long) + 1];

    printf("Enter an integer (q to quit): ");
    while ( scanf("%lu", &val) == 1 )
    {
        itobs(val, bstr);
        show_bstr(bstr);
        putchar ('\n');
        printf("has %d bit(s) on.\n", onbits(val) );
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
int onbits(unsigned long n)
{
    static const int size = CHAR_BIT * sizeof(unsigned long);
    int count = 0;
    int i;

    for (i = 0; i < size; i++, n >>= 1)
    {
        if ( (1UL & n) == 1UL )
        {
            count++;
        }
    }

    return count;
}
