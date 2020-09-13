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
    int ch;
    int len;
    FILE *fp;
    unsigned long count = 0;
    char filename[STRLEN];

    printf("Please enter the filename: ");
    len = read_line_file(filename, 80, stdin);
    if (len <= 0)
    {
        fprintf(stderr, "filename invalid\n");
        exit(EXIT_FAILURE);
    }
    if ( ( fp = fopen(filename, "r") ) == NULL )
    {
        fprintf(stderr, "Can not open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ( ( ch = getc(fp) ) != EOF )
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", filename, count);

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
