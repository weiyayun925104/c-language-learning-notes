/* append.c -- 把文件附加到另一个文件末尾 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 4096
#define STRLEN 128

int append (FILE * source, FILE * dest);

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    FILE *fa, *fs;
    int files = 0;
    char file_app[STRLEN] = {0};
    char file_src[STRLEN] = {0};
    int ch;
    int len;
    int ret;

    puts ("Enter name of destination file:");
    if ( ( len = read_line_file(file_app, 80, stdin) ) <= 0 )
    {
        fprintf (stderr, "Error, file_app is empty.\n");
        exit (EXIT_FAILURE);
    }
    if ( ( fa = fopen (file_app, "ab+") ) == NULL)
    {
        fprintf (stderr, "Can not open file_app \"%s\"\n", file_app);
        exit (EXIT_FAILURE);
    }
    if ( setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fclose (fa);
        fputs ("Can not create output buffer\n", stderr);
        exit (EXIT_FAILURE);
    }
    puts ("Enter name of source file (empty line to quit):");
    while ( ( len = read_line_file(file_src, 80, stdin) ) > 0 )
    {
        if ( strcmp (file_src, file_app) == 0)
        {
            fputs ("Can not append file to itself\n", stderr);
        }
        else if ( ( fs = fopen (file_src, "rb") ) == NULL )
        {
            fprintf (stderr, "Error, Can not open file_src \"%s\"\n", file_src);
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
                fprintf (stderr, "Error in reading file %s.\n", file_src);
            }
            if ( ferror (fa) != 0 )
            {
                fprintf (stderr, "Error in writing file \"%s\"\n", file_app);
            }
            fclose (fs);
            if (ret == 0)
            {
                files++;
                printf ("File %s appended.\n", file_src);
            }
            puts ("Enter name of source file (empty line to quit):");
        }
    }
    printf ("Done appending. %d files appended.\n", files);
    rewind (fa);
    printf ("%s contents:\n", file_app);
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
int read_char (FILE *fp)
{
    int ch = getc(fp);
    if (ch == '\n' || ch == '\t')
    {
        return ' ';
    }
    return ch;
}
int read_word(char *word, int len, FILE *fp)
{
    int ch, pos = 0;
    while ( ( ch = read_char(fp) ) == ' ')
        ;
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
        {
            word[pos++] = ch;
        }
        ch = read_char(fp);
    }
    word[pos] = '\0';
    return pos;
}
int read_line_file(char str[], int n, FILE *fp)
{
    int ch, i = 0;

    while ( isspace ( ch = getc(fp) ) )
        ;
    while ( ch != '\n' && ch != EOF)
    {
        if (i < n)
        {
            str[i++] = ch;
        }
        ch = getc(fp);
    }
    str[i] = '\0';
    return i;
}
