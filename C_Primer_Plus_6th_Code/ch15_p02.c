#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

unsigned long bstr_to_dec(const char * str);
bool check_val(const char * str);

char * itobs (unsigned long, char *);
void show_bstr (const char *);

int main(int argc, char **argv)
{
    unsigned long v1;
    unsigned long v2;
    const size_t STRLEN = CHAR_BIT * sizeof(unsigned long) + 1;
    char bstr[STRLEN];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( !check_val(argv[1]) )
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ( !check_val(argv[2]) )
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    v1 = bstr_to_dec(argv[1]);
    v2 = bstr_to_dec(argv[2]);

    printf("~%s = ", argv[1]);
    itobs(~v1, bstr);
    show_bstr(bstr);
    putchar ('\n');
    printf("~%s = ", argv[2]);
    itobs(~v2, bstr);
    show_bstr(bstr);
    putchar ('\n');
    printf("%s & %s = ", argv[1], argv[2]);
    itobs(v1 & v2, bstr);
    show_bstr(bstr);
    putchar ('\n');
    printf("%s | %s = ", argv[1], argv[2]);
    itobs(v1 | v2, bstr);
    show_bstr(bstr);
    putchar ('\n');
    printf("%s ^ %s = ", argv[1], argv[2]);
    itobs(v1 ^ v2, bstr);
    show_bstr(bstr);
    putchar ('\n');
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
unsigned long bstr_to_dec(const char * str)
{
    unsigned long val = 0;

    while (*str)
    {
        val = 2 * val + ( (*str) - '0');
        str++;
    }

    return val;
}
bool check_val(const char * str)
{
    while (*str)
    {
        if (*str != '0' && *str != '1')
        {
            return false;
        }
        str++;
    }

    return true;
}
