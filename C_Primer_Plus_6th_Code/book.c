/* book.c -- 一本书的图书目录 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct book
{
    char title[STRLEN];
    char author[STRLEN];
    double value;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    int len;
    struct book library;

    printf ("Please enter the book title.\n");
    len = read_line_file(library.title, 80, stdin);
    printf ("Now enter the author.\n");
    len = read_line_file(library.author, 80, stdin);
    printf ("Now enter the value.\n");
    scanf ("%lf", & (library.value) );
    printf ("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf ("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf ("Done.\n");

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
