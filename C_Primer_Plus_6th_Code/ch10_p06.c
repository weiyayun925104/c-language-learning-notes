#include <stdio.h>

#define SIZE 3

void reverse(double array[], int number);

int main(int argc, char **argv)
{
    double array[SIZE] = {1.1, 2.2, 3.3};

    printf("The contents of the array are:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%g\n", array[i]);
    }

    reverse(array, SIZE);

    printf("\nThe contents of the array now are:\n");
    for (int j = 0; j < SIZE; j++)
    {
        printf("%g\n", array[j]);
    }

    return 0;
}

void reverse(double array[], int number)
{
    double temp;
    double *start = array;
    double *end = array + (number - 1);

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
