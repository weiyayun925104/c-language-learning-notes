/* lesser.c -- 找出两个整数中较小的一个 */

#include <stdio.h>

int imin (int a, int b);

int main(int argc, char **argv)
{
    int i, j;

    printf ("Enter a pair of integers (q to quit) : \n");
    while ( scanf ("%d %d", &i, &j) == 2 )
    {
        printf ("The lesser of %d and %d is %d.\n", i, j, imin (i, j) );
        printf ("Enter a pair of integers (q to quit) : \n");
    }
    printf ("Done.\n");

    return 0;
}
int imin (int a, int b)
{
    return ( (a < b) ? a : b );
}
