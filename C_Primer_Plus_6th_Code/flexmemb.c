// flexmemb.c -- �����������Ա

#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores[];
};

void showFlex (const struct flex * p);

int main(int argc, char **argv)
{
    struct flex *pf1, *pf2;
    int n;
    int i;
    double total;

    n = 5;
    total = 0.0;
    pf1 = malloc ( sizeof (struct flex) + ( n * sizeof (double) ) );
    pf1->count = n;
    for (i = 0; i < n; i++)
    {
        pf1->scores[i] = (20.0 - i);
        total += pf1->scores[i];
    }
    pf1->average = total / n;
    showFlex (pf1);
    n = 9;
    total = 0.0;
    pf2 = malloc ( sizeof (struct flex) + ( n * sizeof (double) ) );
    pf2->count = n;
    for (i = 0; i < n; i++)
    {
        pf2->scores[i] = (20.0 - i / 2.0);
        total += pf2->scores[i];
    }
    pf2->average = total / n;
    showFlex (pf2);
    free (pf1);
    free (pf2);

    return 0;
}
void showFlex (const struct flex *p)
{
    int i;

    printf ("Scores: ");
    for (i = 0; i < p->count; i++)
    {
        printf ("%g ", p->scores[i]);
    }
    printf ("\nAverage: %g\n", p->average);
}
