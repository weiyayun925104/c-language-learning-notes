#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fpin, *fpout;
    char *outfile;
    unsigned char byte, next_byte, amount;
    long int position;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s original-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( ( fpin = fopen(argv[1], "rb") ) == NULL )
    {
        fprintf(stderr, "File %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    outfile = malloc(strlen(argv[1]) + 5);
    if (outfile == NULL)
    {
        fprintf(stderr, "Error in outfile: cannot malloc\n");
        fclose(fpin);
        exit(EXIT_FAILURE);
    }
    strcpy(outfile, argv[1]);
    strcat(outfile, ".rle");

    if ( ( fpout = fopen(outfile, "wb") ) == NULL )
    {
        fprintf(stderr, "File %s cannot be written\n", outfile);
        fclose(fpin);
        free(outfile);
        exit(EXIT_FAILURE);
    }
    free(outfile);

    while ( fread (&byte, sizeof(unsigned char), 1, fpin) > 0 )
    {
        amount = 1;
        position = ftell(fpin);
        while ( fread (&next_byte, sizeof(unsigned char), 1, fpin) > 0 && byte == next_byte)
        {
            amount++;
        }
        fwrite(&amount, sizeof(unsigned char), 1, fpout);
        fwrite(&byte, sizeof(unsigned char), 1, fpout);
        fseek(fpin, position + (amount - 1), SEEK_SET);
    }
    fclose(fpin);
    fclose(fpout);

    exit(EXIT_SUCCESS);
}
