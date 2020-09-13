/* prntval.c -- printfµÄ·µ»ØÖµ */

#include <stdio.h>

int main(int argc, char **argv)
{
    int bph2o = 212;
    int rv;

    rv = printf ("%d F is water's boiling point.\n", bph2o);
    printf ("The printf function printed %d characters.\n", rv);

    return 0;
}
