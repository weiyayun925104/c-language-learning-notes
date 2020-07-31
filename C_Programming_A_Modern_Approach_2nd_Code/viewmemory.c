/* Allows the user to view regions of computer memory */

#include <ctype.h>
#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;

int main(int argc, char **argv)
{
    size_t addr;
    int i, n;
    BYTE *ptr;

    printf ("Address of main function: %lx\n", (size_t)main);
    printf ("Address of addr variable: %lx\n", (size_t) (&addr) );
    printf ("\nEnter a (hex) addess: ");
    scanf ("%lx", &addr);
    printf ("Enter number of bytes to view: ");
    scanf ("%d", &n);
    printf ("\n");
    printf ("         Address             Bytes                Characters\n");
    printf ("    ------------   ---------------------------    ----------\n");
    ptr = (BYTE *) addr;
    for (; n > 0; n -= 10)
    {
        printf ("%16lX  ", (size_t) ptr);
        for (i = 0; i < 10 && i < n; i++)
        {
            printf ("%.2X ", *(ptr + i) );
        }
        for (; i < 10; i++)
        {
            printf ("   ");
        }
        printf ("  ");
        for (i = 0; i < 10 && i < n; i++)
        {
            BYTE ch = *(ptr + i);
            if ( !isprint (ch) )
            {
                ch = '.';
            }
            printf ("%c", ch);
        }
        printf ("\n");
        ptr += 10;
    }
    return 0;
}
