
#include <stdio.h>
#include <stdbool.h>

bool isprime(long i);

int main(int argc, char **argv)
{
    long n, i;

    printf("Please enter a positive integer: ");
    scanf("%ld", &n);
    if (n <= 0)
    {
        printf ("%ld is not a positive interger.\n", n);
        return 0;
    }

    printf("All the prime numbers that smaller than or equal to %ld are:\n", n);
    for (i = 2; i <= n; i++)
    {
        if ( isprime(i) )
        {
            printf("%9ld ", i);
        }
        if(i % 8 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}

bool isprime(long i)
{
    long j;
    for (j = 2; (j * j) <= i; j++)
    {
        if (i % j == 0)
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}
