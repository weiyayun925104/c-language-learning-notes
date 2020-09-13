#include <stdio.h>

int main(int argc, char **argv)
{
    int count = 0;
    int ch;

    while ( ( ch = getchar() ) != EOF)
    {
        count++;
    }

    printf("The number of characters in the input is %d.\n", count);

    return 0;
}
