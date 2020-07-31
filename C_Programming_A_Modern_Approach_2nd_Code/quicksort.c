#include "quicksort.h"

void quicksort(int a[], int *low, int *high)
{
    int *middle;
    if (low >= high)
    {
        return;
    }
    middle = split (a, low, high);
    quicksort (a, low, middle - 1);
    quicksort (a, middle + 1, high);
}

int *split(int a[], int *low, int *high)
{
    int part_element = *low;
    for (; ; )
    {
        while (low < high && part_element <= *high)
        {
            high--;
        }
        if (low >= high)
        {
            break;
        }
        *low++ = *high;
        while (low < high && *low <= part_element)
        {
            low++;
        }
        if (low >= high)
        {
            break;
        }
        *high-- = *low;
    }
    *high = part_element;
    return high;
}
