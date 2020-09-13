#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;

    scanf ("%c", &ch);
    while (ch != 'g')
    {
        printf ("%c", ++ch);
        scanf ("%c", &ch);
    }

    return 0;
}
