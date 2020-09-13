// reducto.c - 把文件压缩成原来的1/3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 128

int main(int argc, char **argv)
{
    FILE *in, *out;
    int ch;
    char name[STRLEN] = {0};
    int count = 0;

    if (argc < 2)
    {
        fprintf (stderr, "Usage: %s filename\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    if ( ( in = fopen (argv[1], "r") ) == NULL )
    {
        fprintf (stderr, "can not open input file \"%s\"\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    strncpy (name, argv[1], STRLEN - 5);
    name[STRLEN - 5] = '\0';
    strcat (name, ".red");
    if ( ( out = fopen (name, "w") ) == NULL )
    {
        fclose (in);
        fprintf (stderr, "Can not create output file \"%s\"\n", name);
        exit (EXIT_FAILURE);
    }
    while ( ( ch = getc (in) ) != EOF )
    {
        if ( count++ % 3 == 0)
        {
            putc (ch, out);
        }
    }
    if ( fclose (in) != 0 )
    {
        fprintf (stderr, "Error, can not close input file \"%s\"\n", argv[1]);
    }
    if ( fclose (out) != 0 )
    {
        fprintf (stderr, "Error, can not close output file \"%s\"\n", name);
    }

    return 0;
}
