#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char ch;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: allcaps filename\n");
        exit(EXIT_FAILURE);
    }

    if ( ( fp = fopen(argv[1], "r") ) != NULL )
    {
        while ( ( ch = getc(fp) ) != EOF )
        {
            if ( isalpha(ch) )
            {
                putchar( toupper(ch) );
            }
            else
            {
                putchar(ch);
            }
        }
        fclose(fp);
    }
    else
    {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
