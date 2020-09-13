#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void drop_space(char *s);

int main(int argc, char **argv)
{
    char orig[STRLEN];
    int len;

    puts("Enter a string:");
    while ( ( len = read_line_file(orig, 80, stdin) ) > 0 )
    {
        drop_space(orig);
        puts(orig);
        puts("Enter a string:");
    }
    puts("Done.");

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
void drop_space(char *s)
{
    char *pos;
    char *newpos;
    char temp;

    while (*s)
    {
        if (*s == ' ')
        {
            pos = s;
            newpos = s + 1;
            while (*newpos == ' ')
            {
                newpos++;
            }
            do
            {
                temp = *newpos;
                *pos = *newpos;
                pos++;
                newpos++;
            }
            while (temp != '\0');
        }
        else
        {
            s++;
        }
    }
}
