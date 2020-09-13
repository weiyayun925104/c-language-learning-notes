#include <stdio.h>

#define SIZE 3

int function(int array[], int number);

int main(int argc, char **argv)
{
    int array[SIZE] = {1, 2, 3};

    printf("The largest value stored in the array is %d.\n", function(array, SIZE));

    return 0;
}

int function(int array[], int number)
{
    int largest = *array;

    for (int i = 1; i < number; i++)
    {
        if ( *(array + i) > largest )
        {
            largest = *(array + i);
        }
    }

    return largest;
}
