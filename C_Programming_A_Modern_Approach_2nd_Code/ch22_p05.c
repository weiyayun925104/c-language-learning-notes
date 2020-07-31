/* Performs XOR encryption */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char **argv)
{
    int orig_char, new_char;
    FILE *fpin, *fpout;

    if (argc != 3)
    {
        fprintf(stderr, "USAGE: xor input_filename output_filename\n");
        exit(EXIT_FAILURE);
    }

    if ( ( fpin = fopen(argv[1], "rb") ) == NULL )
    {
        fprintf(stderr, "Error: %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ( ( fpout = fopen(argv[2], "wb") ) == NULL )
    {
        fprintf(stderr, "Error: %s cannot be created\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ( ( orig_char = getc(fpin) ) != EOF )
    {
        new_char = orig_char ^ KEY;
        putc (new_char, fpout);
    }

    fclose(fpin);
    fclose(fpout);
    exit(EXIT_SUCCESS);
}
