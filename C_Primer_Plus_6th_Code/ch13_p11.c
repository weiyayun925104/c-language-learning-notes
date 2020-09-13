#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 512

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    FILE *fp;
    int len;
    char line[STRLEN] = {0};

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( ( fp = fopen(argv[2], "r") ) == NULL )
    {
        fprintf(stderr, "Can not open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while ( ( len = read_line_file(line, 256, fp) ) > 0 )
    {
        if ( strstr(line, argv[1]) != NULL )
        {
            puts(line);
        }
    }
    fclose(fp);

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
