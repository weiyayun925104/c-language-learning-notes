#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

char * itobs (unsigned long, char *);
void show_bstr (const char *);
unsigned long one_or_zero(unsigned long val, int bit_pos);

int main(int argc, char **argv)
{
    unsigned long val;
    int bit_pos;
    char bstr[CHAR_BIT * sizeof(unsigned long) + 1];

    printf("Enter an integer and a bit position (q to quit): ");
    while ( scanf("%lu %d", &val, &bit_pos) == 2 )
    {
        itobs(val, bstr),
        show_bstr(bstr);
        putchar ('\n');
        printf("has bit %lu on position %d.\n", one_or_zero(val, bit_pos), bit_pos);
        printf("Enter an integer and a bit position (q to quit): ");
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
unsigned long one_or_zero(unsigned long val, int bit_pos)
{
    for (int i = 0; i < bit_pos; i++)
    {
        val >>= 1;
    }

    return (1UL & val);
}
