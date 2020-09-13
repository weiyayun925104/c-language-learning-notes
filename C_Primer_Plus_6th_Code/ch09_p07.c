#include <stdio.h>
#include <ctype.h>

int report(int ch);

int main(int argc, char **argv)
{
    int ch;

    printf("Please enter your characters: \n");
    while ( ( ch = getchar() ) != EOF )
    {
        if (report(ch) == -1 && ch != '\n')
        {
            printf("%c isn't a letter.\n", ch);
        }
        else if (report(ch) == -1 && ch == '\n')
        {
            printf("Please enter your characters: \n");
        }
        else
        {
            printf("%c is a letter, its numeric location in the alphabet is %d.\n", ch, report(ch));
        }
    }

    printf("Done.\n");

    return 0;
}

int report(int ch)
{
    if ( isalpha(ch) )
    {
        if ( isupper(ch) )
        {
            return (ch - 64);
        }
        else
        {
            return (ch - 96);
        }
    }
    else
    {
        return -1;
    }
}

