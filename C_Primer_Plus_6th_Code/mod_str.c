/* mod_str.c -- ÐÞ¸Ä×Ö·û´® */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void ToUpper (char * str);
int PunctCount (const char * str);

int main(int argc, char **argv)
{
    char line[SIZE];
    int len;

    puts ("Please enter a line:");
    len = read_line_file(line, 80, stdin);
    if (len > 0)
    {
        ToUpper (line);
        puts (line);
        printf ("That line has %d punctuation characters.\n", PunctCount (line) );
    }
    printf("Done.\n");

    return 0;
}
void ToUpper (char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
int PunctCount (const char * str)
{
    int count = 0;

    while (*str)
    {
        if ( ispunct (*str) )
        {
            count++;
        }
        str++;
    }

    return count;
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
