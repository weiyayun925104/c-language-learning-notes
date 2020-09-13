#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    char ch;

    for (i = 0, ch= 'A'; i < 4; i++, ch += 2 * i)
    {
        printf ("%c", ch);
    }

    return 0;
}
