#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define TIMES 1000

int main(int argc, char **argv)
{
    int i, j, k;
    int arr[SIZE];

    for (j = 0; j < 10; j++)
    {
        printf("Round %d\n", j);
        for (k = 0; k < 10; k++)
        {
            arr[k] = 0;
        }
        srand( (unsigned int) time(NULL) );
        for (i = 0; i < TIMES; i++)
        {
            arr[rand() % 10]++;
        }
        printf("The times each number was produced:\n");
        for (k = 0; k < 10; k++)
        {
            printf("%d: %d times\n", k + 1, arr[k]);
        }
        printf("\n");
    }

    return 0;
}
