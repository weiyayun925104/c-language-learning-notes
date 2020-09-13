#include <stdio.h>

char buffer[8192];
int array[8192];

void init(int n)
{
    int i, j, len = 0;
    for(i = 1; i <= n; i++)
    {
        buffer[i] = 0;
    }
    for(i = 2; i <= n; i++)
    {
        if(buffer[i] == 0)
        {
            array[len] = i;
            printf(" %8d ", i);
            len++;
        }
        if( i <= ( (n / 2) + 1) )
        {
            for(j = 0; j < len && array[j]*i <= n; j++)
            {
                buffer[array[j]*i] = 1;
                if(i % array[j] == 0)
                {
                    break;
                }
            }
        }
    }
}
int main(int argc, char **argv)
{
    int  n;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf ("%d is not a positive interger.\n", n);
        return 0;
    }

    printf("All the prime numbers that smaller than or equal to %d are:\n", n);

    init(n);

    return 0;
}
