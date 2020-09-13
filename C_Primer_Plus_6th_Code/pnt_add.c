// pnt_add.c -- ÷∏’Îµÿ÷∑

#include <stdio.h>

#define SIZE 4

int main(int argc, char **argv)
{
    int dates[SIZE];
    int * pti;
    int index;
    double bills[SIZE];
    double * ptf;

    pti = dates;
    ptf = bills;
    printf ("%23s %15s\n", "int", "double");
    for (index = 0; index < SIZE; index++)
    {
        printf ("pointers + %d: %p %p\n", index, pti + index, ptf + index);
    }

    return 0;
}
