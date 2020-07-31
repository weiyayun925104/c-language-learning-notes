#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char ch;

    while ( ( ch = getchar() ) != EOF )
    {
        if ( strchr("\a\b\f\r\t\v", ch) != NULL )
        {
            putchar('?');
        }
        else
        {
            putchar(ch);
        }
    }

    return 0;
}
