/* for_down.c */

#include <stdio.h>

int main(int argc, char **argv)
{
    int secs;

    for (secs = 5; secs > 0; secs--)
    {
        printf ("%d seconds!\n", secs);
    }
    printf ("We have ignition!\n");

    return 0;
}
