/* scan_str.c --  π”√scanf */

#include <stdio.h>

int main(int argc, char **argv)
{
    char name1[11], name2[11];
    int count;

    printf ("Please enter 2 names:\n");
    count = scanf ("%5s %10s", name1, name2);
    printf ("I read the %d names %s and %s.\n", count, name1, name2);

    return 0;
}
