#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    FILE *in, *out;
    int ch;
    int len;
    char sour_name[STRLEN] = {0};
    char dest_name[STRLEN] = {0};
    int count = 0;

    printf("Please enter the source file name: ");
    len = read_line_file(sour_name, 80, stdin);
    if (len <= 0)
    {
        fprintf(stderr, "source filename invalid\n");
        exit(EXIT_FAILURE);
    }
    if ( ( in = fopen (sour_name, "r") ) == NULL )
    {
        fprintf (stderr, "can not open input file %s\n", sour_name);
        exit (EXIT_FAILURE);
    }
    strncpy (dest_name, sour_name, STRLEN - 5);
    dest_name[STRLEN - 5] = '\0';
    strcat (dest_name, ".red");
    if ( ( out = fopen (dest_name, "w") ) == NULL )
    {
        fclose (in);
        fprintf (stderr, "Can not create output file %s\n", dest_name);
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
        fprintf (stderr, "Error, can not close input file %s\n", sour_name);
    }
    if ( fclose (out) != 0 )
    {
        fprintf (stderr, "Error, can not close output file %s\n", dest_name);
    }

    return 0;
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
