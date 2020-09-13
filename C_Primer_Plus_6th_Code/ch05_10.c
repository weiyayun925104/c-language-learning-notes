#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 0;
    while(++x < 3)
    {
        printf ("%4d", x);
    }
    printf("\n");

    x = 100;
    while (x++ < 103)
    {
        printf ("%4d\n", x);
    }
    printf ("%4d\n", x);

    char ch = 's';

    while (ch < 'w')
    {
        printf ("%c", ch);
        ch++;
    }
    printf ("%c\n", ch);

    return 0;
}
