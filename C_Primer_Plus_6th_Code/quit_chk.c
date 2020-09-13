/* quit_chk.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128
#define LIM 10
#define STOP "quit"

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    char input[LIM][SIZE];
    int len;
    int count = 0;

    printf ("Enter up to %d lines (type quit to quit) :\n", LIM);
    while ( count < LIM &&  ( len = read_line_file(input[count], 80, stdin) ) > 0 && strcmp(input[count], STOP) != 0 )
    {
        count++;
    }
    printf ("%d strings entered\n", count);

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
