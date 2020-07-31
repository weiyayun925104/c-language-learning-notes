#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char c, d = '\0';
    int count = 0;

    while ( ( c = getchar() ) != EOF )
    {
        if ( strchr(".?!", d) != NULL && isspace(c) )
        {
            count++;
        }
        d = c;
    }

    printf("Number of sentences: %d\n", count);

    return 0;
}

