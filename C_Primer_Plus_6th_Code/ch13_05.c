#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 256

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int has_ch (char ch, const char * line);

int main(int argc, char **argv)
{
    FILE *fp;
    int len;
    char ch;
    char line[BUFSIZE];

    if (argc != 3)
    {
        fprintf (stderr, "Usage: %s character filename\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    ch = argv[1][0];
    if ( ( fp = fopen (argv[2], "r") ) == NULL )
    {
        fprintf (stderr, "Can not open %s\n", argv[2]);
        exit (EXIT_FAILURE);
    }
    while ( ( len = read_line_file(line, BUFSIZE, fp) ) > 0 )
    {
        if ( has_ch (ch, line) )
        {
            puts (line);
        }
    }
    fclose (fp);

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
int has_ch (char ch, const char * line)
{
    while (*line)
    {
        if (ch == *line)
        {
            return 1;
        }
        line++;
    }

    return 0;
}
