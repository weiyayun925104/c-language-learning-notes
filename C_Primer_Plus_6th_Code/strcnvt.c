/* strcnvt.c --  π”√strtol */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    char number[SIZE];
    char * end;
    long value;
    int len;

    puts ("Enter a number (empty line to quit) :");
    while ( ( len = read_line_file(number, 80, stdin) ) > 0 )
    {
        value = strtol (number, &end, 10);
        printf ("base 10 input, base 10 output: %ld, stopped at %s (%d) \n", value, end, *end);
        value = strtol (number, &end, 16);
        printf ("base 16 input, base 10 output: %ld, stopped at %s (%d) \n", value, end, *end);
        puts ("Enter a number (empty line to quit) :");
    }
    puts ("Done.\n");

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
