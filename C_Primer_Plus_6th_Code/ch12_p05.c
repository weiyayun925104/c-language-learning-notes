#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(const int array[], int limit);
void sort(int array[], int limit);

#define SIZE 100

int main(int argc, char **argv)
{
    int i;
    int arr[SIZE];

    srand( (unsigned int) time(NULL) );
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = ( rand() % 10 ) + 1;
    }
    puts("initial array");
    print(arr, SIZE);
    sort(arr, SIZE);
    puts("\nsorted array");
    print(arr, SIZE);

    return 0;
}
void sort(int array[], int limit)
{
    int top, search, temp;

    for (top = 0; top < limit - 1; top++)
    {
        for (search = top + 1; search < limit; search++)
        {
            if (array[top] > array[search])
            {
                temp = array[top];
                array[top] = array[search];
                array[search] = temp;
            }
        }
    }
}
void print(const int array[], int limit)
{
    int index;

    for (index = 0; index < limit; index++)
    {
        printf("%2d ", array[index]);
        if (index % 10 == 9)
        {
            putchar('\n');
        }
    }
    if (index % 10 != 0)
    {
        putchar('\n');
    }
}
