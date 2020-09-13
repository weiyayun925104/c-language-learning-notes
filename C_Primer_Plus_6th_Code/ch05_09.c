#include <stdio.h>

int main(int argc, char **argv)
{
    char ch = 'a';

    while (ch <= 'g')
    {
        printf ("%5c", ch++);
    }
    printf ("\n");

    return 0;
}
