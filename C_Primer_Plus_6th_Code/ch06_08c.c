#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;

    do
    {
        scanf ("%c", &ch);
        printf ("%c", ch);
    } while (ch != 'g');

    return 0;
}
