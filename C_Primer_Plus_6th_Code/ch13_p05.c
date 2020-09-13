#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 4096
#define STRLEN 128

int append (FILE * source, FILE * dest);

int main(int argc, char **argv)
{
    FILE *fa, *fs;
    int files = 0;
    int ch;
    int ret;
    int filecnt;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s appendfile sourcefile[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ( ( fa = fopen(argv[1], "ab+") ) == NULL )
    {
        fprintf(stderr, "Can not open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ( setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0 )
    {
        fclose (fa);
        fprintf(stderr, "Can not create output buffer\n");
        exit(EXIT_FAILURE);
    }
    for (filecnt = 2; filecnt < argc; filecnt++)
    {
        if ( strcmp (argv[filecnt], argv[1]) == 0)
        {
            fprintf (stderr, "Can not append file to itself\n");
        }
        else if ( ( fs = fopen (argv[filecnt], "rb") ) == NULL )
        {
            fprintf (stderr, "Error, Can not open %s\n", argv[filecnt]);
        }
        else
        {
            if ( setvbuf (fs, NULL, _IOFBF, BUFSIZE ) != 0 )
            {
                fclose (fs);
                fputs ("Can not create input buffer\n", stderr);
                continue;
            }
            ret = append (fs, fa);
            if ( ferror (fs) != 0 )
            {
                fprintf (stderr, "Error in reading file %s\n", argv[filecnt]);
            }
            if ( ferror (fa) != 0 )
            {
                fprintf (stderr, "Error in writing file %s\n", argv[1]);
            }
            fclose (fs);
            if (ret == 0)
            {
                files++;
                printf ("File %s appended.\n", argv[filecnt]);
            }
        }
    }
    printf ("Done appending. %d files appended.\n", files);
    rewind (fa);
    printf ("%s contents:\n", argv[1]);
    while ( ( ch = getc (fa) ) != EOF )
    {
        putchar (ch);
    }
    puts ("Done displaying.");
    fclose (fa);

    return 0;
}
int append (FILE * source, FILE * dest)
{
    int ret = 0;
    size_t write_bytes = 0;
    size_t read_bytes = 0;
    static unsigned char temp[BUFSIZE] = {0};

    while ( ( read_bytes = fread (temp, sizeof (unsigned char), BUFSIZE, source) ) == BUFSIZE )
    {
        write_bytes = fwrite (temp, sizeof (unsigned char), read_bytes, dest);
        if ( write_bytes != read_bytes )
        {
            ret = 2;
            return ret;
        }
    }
    if (read_bytes > 0)
    {
        write_bytes = fwrite (temp, sizeof (unsigned char), read_bytes, dest);
        if ( write_bytes != read_bytes )
        {
            ret = 2;
            return ret;
        }
    }

    return ret;
}
