// truth.c -- 哪些值为真

#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 3;

    while (n)
    {
        printf ("%d is true\n", n--);
    }
    printf ("%d is false\n", n);

    n = -3;
    while (n)
    {
        printf ("%d is true\n", n++);
    }
    printf ("%d is false\n", n);

    return 0;
}
