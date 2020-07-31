/* Copies a file */
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(int argc, char **argv)
{
    FILE *source_fp, *dest_fp;
    char buffer[BUFSIZE];
    int read;

    if ( argc != 3)
    {
        fprintf (stderr, "usage: %s source dest\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    if ( ( source_fp = fopen (argv[1], "rb") ) == NULL )
    {
        fprintf (stderr, "Can't open %s\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    if ( ( dest_fp = fopen (argv[2], "wb") ) == NULL )
    {
        fprintf (stderr, "Can't open %s\n", argv[2]);
        fclose (source_fp);
        exit (EXIT_FAILURE);
    }

    while ( ( read = fread (buffer, sizeof(char), BUFSIZE, source_fp) ) > 0 )
    {
        fwrite(buffer, sizeof(char), read, dest_fp);
    }

    fclose (source_fp);
    fclose (dest_fp);
    return 0;
}
