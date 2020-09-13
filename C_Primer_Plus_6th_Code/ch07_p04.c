#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;
    int count = 0;

    printf("Please enter your characters: ");
    while ( ( ch = getchar() ) != '#' )
    {
        if (ch == '.')
        {
            putchar('!');
            count++;
        }
        else if (ch == '!')
        {
            putchar('!');
            putchar('!');
            count++;
        }
        else
        {
            putchar(ch);
        }
    }

    printf("\nIt has made %d substitutions.\n", count);

    return 0;
}
