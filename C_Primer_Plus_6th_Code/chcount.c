// chcount.c -- ʹ���߼��������

#include <stdio.h>

#define PERIOD '.'

int main(int argc, char **argv)
{
    char ch;
    int charcount = 0;

    while ( ( ch = getchar() ) != PERIOD)
    {
        if ( ch != '"' && ch != '\'' )
        {
            charcount++;
        }
    }
    printf ("There are %d non-quote characters.\n", charcount);

    return 0;
}
