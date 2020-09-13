#include <stdio.h>

void function(double *i, double *j, double *k);

int main(int argc, char **argv)
{
    double i, j, k;

    printf("Please enter three numbers: ");
    while ( scanf("%lf %lf %lf", &i, &j, &k) == 3 )
    {
        function(&i, &j, &k);
        printf("i = %g, j = %g, k = %g.\n", i, j, k);
        printf("Please enter three numbers (q to quit): ");
    }

    printf("Done.\n");

    return 0;
}

void function(double *i, double *j, double *k)
{
    double temp, temp1;

    if ( (*i) < (*j) )
    {
        if ( (*i) < (*k) )
        {
            if ( (*j) > (*k) )
            {
                temp = (*j);
                (*j) = (*k);
                (*k) = temp;
            }
        }
        else
        {
            temp = (*i);
            (*i) = (*k);
            temp1 = (*j);
            (*j) = temp;
            (*k) = temp1;
        }
    }
    else
    {
        if ( (*i) < (*k) )
        {
            temp = (*i);
            (*i) = (*j);
            (*j) = temp;
        }
        else
        {
            if ( (*j) < (*k) )
            {
                temp = (*i);
                (*i) = (*j);
                temp1 = (*k);
                (*j) = temp1;
                (*k) = temp;
            }
            else
            {
                temp = (*i);
                (*i) = (*k);
                (*k) = temp;
            }
        }
    }
}
