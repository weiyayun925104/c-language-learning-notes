#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *file;
    int ch;
    int count;
    int filecnt;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s character filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (filecnt = 2; filecnt < argc; filecnt++)
    {
        if ( ( file = fopen (argv[filecnt], "r") ) == NULL )
        {
            fprintf(stderr, "Can not open %s\n", argv[filecnt]);
        }
        else
        {
            count = 0;
            ch = getc(file);
            while (ch != EOF)
            {
                if (argv[1][0] == ch)
                {
                    count++;
                }
                ch = getc(file);
            }
            if ( ferror(file) != 0 )
            {
                fprintf(stderr, "Error in reading file %s.\n", argv[filecnt]);
            }
            else
            {
                printf("The character %s has appeared in file %s for %d times.\n",
                       argv[1], argv[filecnt], count);
            }
            fclose(file);
        }
    }

    return 0;
}
