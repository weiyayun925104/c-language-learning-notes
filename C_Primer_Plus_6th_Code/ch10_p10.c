#include <stdio.h>

#define SIZE 4

void function(int array1[], int array2[], int array3[], int number);

int main(int argc, char **argv)
{
    int array1[SIZE] = {2, 4, 5, 8};
    int array2[SIZE] = {1, 0, 4, 6};
    int array3[SIZE];

    function(array1, array2, array3, SIZE);

    printf("The contents of the third array:\n");
    for (int j = 0; j < SIZE; j++)
    {
        printf("%d ", array3[j]);
    }
    printf("\n");

    return 0;
}

void function(int array1[], int array2[], int array3[], int number)
{
    for (int i = 0; i < number; i++)
    {
        array3[i] = array1[i] + array2[i];
    }
}
