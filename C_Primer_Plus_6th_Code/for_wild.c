/* for_wild.c */

#include <stdio.h>

int main(int argc, char **argv)
{
    int x;
    int y = 55;

    for (x = 1; y <= 75; y = (++x * 5) + 50)
    {
        printf ("%10d %10d\n", x, y);
    }

    return 0;
}
