#include <stdio.h>

#define SIZE 8

int main(int argc, char **argv)
{
    int two_powers[SIZE];
    int value = 1;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        two_powers[i] = value;
        value *= 2;
    }

    i = 0;
    do
    {
        printf("%d ", two_powers[i]);
    }
    while (++i < SIZE);

    return 0;
}
