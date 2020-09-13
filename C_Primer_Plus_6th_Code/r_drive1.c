/* r_drive1.c -- ≤‚ ‘rand1∫Õsrand1 */

#include <stdio.h>
#include <stdlib.h>

extern void srand1 (unsigned long int seed);
extern int rand1 (void);

int main(int argc, char **argv)
{
    int count;
    int ret;
    unsigned long int seed;

    printf ("Please enter your choice for seed:\n");
    while ( ( ret = scanf ("%lu", &seed) ) == 1)
    {
        srand1 (seed);
        for (count = 0; count < 5; count++)
        {
            printf ("%d\n", rand1() );
        }
        printf ("Please enter your choice for seed:\n");
    }
    printf ("Done.\n");

    return 0;
}
