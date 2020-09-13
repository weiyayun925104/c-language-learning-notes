#include <stdio.h>

#define SIZE 3

double function(double array[], int number);

int main(int argc, char **argv)
{
    double array[SIZE] = {1.2, 2.3, 3.4};

    printf("The largest value stored in the array is %.2f.\n", function(array, SIZE));

    return 0;
}

double function(double array[], int number)
{
    double largest = *array;
    double smallest = *array;

    for (int i = 1; i < number; i++)
    {
        if (*(array + i) > largest)
        {
            largest = *(array + i);
        }
        if (*(array + i) < smallest)
        {
            smallest = *(array + i);
        }
    }

    return (largest - smallest);
}
