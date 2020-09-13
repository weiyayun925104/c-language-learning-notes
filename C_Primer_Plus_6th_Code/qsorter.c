/* qsorter.c -- 用qsort排序一组数字 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 40

void fillarray (double ar[], int n);
void showarray (const double ar[], int n);
int mycomp (const void * p1, const void * p2);

int main(int argc, char **argv)
{
    double vals[NUM];

    srand ( (unsigned int) time (NULL) );
    fillarray (vals, NUM);
    puts ("Random list:");
    showarray (vals, NUM);
    qsort (vals, NUM, sizeof (double), mycomp);
    puts ("\nSorted list:");
    showarray (vals, NUM);

    return 0;
}
void fillarray (double ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        ar[index] = (double) rand() / ( (double) rand() + 0.1 );
    }
}
void showarray (const double ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf ("%9.4f ", ar[index]);
        if ( index % 6 == 5 )
        {
            putchar ('\n');
        }
    }
    if ( index % 6 != 0 )
    {
        putchar ('\n');
    }
}
int mycomp (const void * p1, const void * p2)
{
    if ( *( (double *) p1) < *( (double *) p2) )
    {
        return -1;
    }
    else if ( *( (double *) p1) == *( (double *) p2) )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
