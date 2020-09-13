/* addaword.c --  π”√fprintf°¢fscanf∫Õrewind */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 128

int main(int argc, char **argv)
{
    FILE * fp;
    int ret;
    char words[STRLEN] = {0};

    if (argc < 2)
    {
        fprintf (stderr, "Usage: %s filename\n", argv[0]);
        exit (EXIT_FAILURE);
    }

    if ( ( fp = fopen (argv[1], "a+") ) == NULL )
    {
        fprintf (stderr, "Can not open output file \"%s\"\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    puts ("Enter words to add to the file; press the # key at the beginning of a line to terminate.");
    while ( ( (ret = fscanf (stdin, "%40s", words) ) == 1 ) && ( words[0] != '#' ) )
    {
        fprintf (fp, "%s\n", words);
    }
    puts ("File contents:");
    rewind (fp);
    while ( ( ret = fscanf (fp, "%s", words) ) == 1 )
    {
        puts (words);
    }
    puts ("Done.");
    if ( fclose (fp) != 0 )
    {
        fprintf (stderr, "Error, can not close output file.\n");
    }

    return 0;
}
