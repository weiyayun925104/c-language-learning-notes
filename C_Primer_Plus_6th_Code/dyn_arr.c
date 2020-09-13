/* dyn_arr.c -- 动态分配数组 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    double * ptd;
    int max;
    int number;
    int ret;
    int i = 0;

    puts ("What is the maximum number of type double entries?");
    if ( scanf ("%d", &max) != 1 )
    {
        puts ("Error, number not correctly entered.");
        exit (EXIT_FAILURE);
    }
    ptd = malloc ( max * sizeof (double) );
    if (ptd == NULL)
    {
        puts ("Error, memory allocation failed.");
        exit (EXIT_FAILURE);
    }
    puts ("Enter the values (q to quit) :");
    while (i < max && ( ret = scanf ("%lf", &ptd[i]) ) == 1)
    {
        ++i;
    }
    number = i;
    printf ("Here are your %d entries:\n", number);
    for (i = 0; i < number; i++)
    {
        printf ("%8.2f ", ptd[i]);
        if (i % 8 == 7)
        {
            putchar ('\n');
        }
    }
    putchar ('\n');
    puts ("Done.");
    free (ptd);

    return 0;
}
