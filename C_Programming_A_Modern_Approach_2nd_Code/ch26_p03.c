#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int compare_intnums (const void *p, const void *q);

int main(int argc, char **argv)
{
    int a[N], i;
    clock_t start_clock;

    for (i = 0; i < N; i++)
    {
        a[i] = N - i;
    }
    start_clock = clock();
    qsort(a, N, sizeof(int), compare_intnums);

    printf ("Time to sort %d ints: %g sec.\n", N, ( clock() - start_clock ) / (double) CLOCKS_PER_SEC );
    return 0;
}

int compare_intnums (const void *p, const void *q)
{
    if ( *( (int *)p) < * ( (int *)q) )
    {
        return -1;
    }
    else if ( *( (int *)p) == *( (int *)q) )
    {
        return 0;
    }

    return 1;
}
