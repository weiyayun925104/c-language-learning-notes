/* format.c -- ¸ñÊ½»¯×Ö·û´® */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 32
#define SIZE 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    char first[STRLEN];
    char last[STRLEN];
    char formal[SIZE];
    double prize;

    puts ("Enter your first name:");
    read_line_file(first, 20, stdin);
    puts ("Enter your last name:");
    read_line_file(last, 20, stdin);
    puts ("Enter your prize money:");
    scanf ("%lf", &prize);
    sprintf (formal, "%s, %-19s: $%.2f\n", last, first, prize);
    puts (formal);

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
