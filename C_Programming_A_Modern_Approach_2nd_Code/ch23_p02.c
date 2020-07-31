#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    bool ready_to_copy = false;
    char ch;

    while ( ( ch = getchar() ) != EOF )
    {
        if (ready_to_copy)
        {
            putchar(ch);
        }
        else if ( !isspace(ch) )
        {
            ready_to_copy = true;
            putchar(ch);
        }
        if (ch == '\n')
        {
            ready_to_copy = false;
        }
    }

    return 0;
}
