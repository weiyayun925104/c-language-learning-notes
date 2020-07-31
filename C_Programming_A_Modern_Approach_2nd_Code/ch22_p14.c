#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fpin, *fpout;
    char ch, *outfile;
    int n;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s filename(to be encrypted)\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( ( fpin = fopen(argv[1], "r") ) == NULL )
    {
        fprintf(stderr, "Error: file %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    outfile = malloc(strlen(argv[1]) + 4 + 1);
    if (outfile == NULL)
    {
        fprintf(stderr, "Error in outfile: cannot malloc\n");
        fclose(fpin);
        exit(EXIT_FAILURE);
    }
    strcpy(outfile, argv[1]);
    strcat(outfile, ".enc");

    if ( ( fpout = fopen(outfile, "w") ) == NULL )
    {
        fprintf(stderr, "Error: file %s cannot be written\n", outfile);
        fclose(fpin);
        free(outfile);
        exit(EXIT_FAILURE);
    }
    free(outfile);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);

    while ( ( ch = getc(fpin) ) != EOF )
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            putc( ( (ch - 'A') + n) % 26 + 'A', fpout );
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            putc( ( (ch - 'a') + n) % 26 + 'a', fpout );
        }
        else
        {
            putc(ch, fpout);
        }
    }
    fclose(fpin);
    fclose(fpout);

    exit(EXIT_SUCCESS);
}
