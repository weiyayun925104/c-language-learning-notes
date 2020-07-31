#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fpin, *fpout;
    char ch;

    if (argc != 3)
    {
        fprintf(stderr, "USAGE: %s input-file output-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( ( fpin = fopen(argv[1], "rb") ) == NULL )
    {
        fprintf(stderr, "Error: file %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ( ( fpout = fopen(argv[2], "wb") ) == NULL )
    {
        fprintf(stderr, "Error: file %s cannot be written\n", argv[2]);
        fclose(fpin);
        exit(EXIT_FAILURE);
    }

    while ( ( ch = getc(fpin) ) != EOF )
    {
        if ( ch != '\x0d' && ch != '\x1a' )
        {
            fputc(ch, fpout);
        }
    }

    fclose(fpin);
    fclose(fpout);

    exit(EXIT_SUCCESS);
}
