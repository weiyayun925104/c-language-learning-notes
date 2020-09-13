#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;
    int count = 0;

    printf("Please enter your characters: ");
    while ( ( ch = getchar() ) != '#' )
    {
        count++;
        printf("%c%5d ", ch, ch);

        if ( (count % 8) == 0)
        {
            printf("\n");
        }
    }

    return 0;
}
