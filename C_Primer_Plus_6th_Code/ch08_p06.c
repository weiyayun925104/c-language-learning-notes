#include <stdio.h>
#include <ctype.h>

int get_first (void);

int main(int argc, char **argv)
{
    int ch;

    printf("Enter your characters: ");
    ch = get_first();
    printf("The first non-whitespace character encountered is %c.\n", ch);

    return 0;
}
int get_first (void)
{
    int ch;

    while ( isspace( ch = getchar() ) )
    {
        continue;
    }
    while ( getchar() != '\n' )
    {
        continue;
    }

    return ch;
}
