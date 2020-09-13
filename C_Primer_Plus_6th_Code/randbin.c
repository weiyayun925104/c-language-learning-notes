/* randbin.c -- �ö�����I/O����������� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARSIZE 1000

int main(int argc, char **argv)
{
    double numbers[ARSIZE];
    double value;
    const char * file = "numbers.dat";
    int i;
    int ret;
    long pos;
    FILE * iofile;

    for (i = 0; i < ARSIZE; i++)
    {
        numbers[i] = (100.0 * i) + ( 1.0 / (i + 1) );
    }
    if ( ( iofile = fopen (file, "wb") ) == NULL )
    {
        fprintf (stderr, "Could not open file %s for output.\n", file);
        exit (EXIT_FAILURE);
    }
    fwrite (numbers, sizeof (double), ARSIZE, iofile);
    fclose (iofile);
    if ( ( iofile = fopen (file, "rb") ) == NULL )
    {
        fprintf (stderr, "Could not open file %s for random access.\n", file);
        exit (EXIT_FAILURE);
    }
    printf ("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while ( ( ret = scanf ("%d", &i) ) == 1 && i >= 0 && i < ARSIZE )
    {
        pos = ( (long) i ) * sizeof (double);
        fseek (iofile, pos, SEEK_SET);
        fread (&value, sizeof (double), 1, iofile);
        printf ("The value there is %g.\n", value);
        printf ("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    }
    fclose (iofile);
    puts ("Done.");

    return 0;
}
