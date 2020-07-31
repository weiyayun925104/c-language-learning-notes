#include <stdio.h>

#define MAX_LEN 100

void selection_sort(int a[], int n);

int main(int argc, char **argv)
{
    int i, c, n, a[MAX_LEN];
    printf("Enter list of integers to be sorted: ");
    for (i = 0, n = 0; i < MAX_LEN; i++)
    {
        scanf(" %d", &a[i]);
        n++;
        if ( (c = getchar()) == '\n' )
        {
            break;
        }
        ungetc(c, stdin);
    }

    selection_sort(a, n);

    printf("Sorted list:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n)
{
    if (n < 2) return;

    int i, temp, largest = 0;

    for (i = 1; i < n; i++)
    {
        if (a[i] > a[largest])
        {
            largest = i;
        }
    }
    if(largest < n - 1)
    {
        temp = a[largest];
        a[largest] = a[n - 1];
        a[n - 1] = temp;
    }
    selection_sort(a, n - 1);
}
