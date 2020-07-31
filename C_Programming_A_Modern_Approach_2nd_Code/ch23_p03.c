#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    char ch;
    bool in_word = false;

    while ( ( ch = getchar() ) != EOF )
    {
        if ( isalpha(ch) && !in_word )
        {
            putchar( toupper(ch) );
            in_word = true;
        }
        else if ( isspace(ch) )
        {
            in_word = false;
            putchar(ch);
        }
        else
        {
            putchar(ch);
        }
    }

    return 0;
}
