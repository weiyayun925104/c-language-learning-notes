#include <stdio.h>

#define SIZE 3

int function(double array[], int number);

int main(int argc, char **argv)
{
    double array[SIZE] = {1.1, 2.2, 3.3};

    printf("The index of the largest value stored in the array is %d.\n", function(array, SIZE));

    return 0;
}

int function(double array[], int number)
{
    int largest = *array;
    int largest_index = 0;

    for (int i = 1; i < number; i++)
    {
        if (*(array + i) > largest)
        {
            largest = *(array + i);
            largest_index = i;
        }
    }

    return largest_index;
}
