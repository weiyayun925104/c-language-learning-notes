#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int i;
    char ch;

    if (argc < 2)
    {
        fprintf(stderr, "USAGE: fcat filename filename2 ...\n");
        exit(EXIT_FAILURE);
    }
    
    for (i = 1; i < argc; i++)
    {
        if ( ( fp = fopen (argv[i], "r") ) == NULL )
        {
            fprintf(stderr, "Error: file %s cannot be opened\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        else
        {
            while ( ( ch = getc(fp) ) != EOF )
            {
                putchar(ch);
            }
            fclose(fp);
        }
    }

    exit(EXIT_SUCCESS);
}
