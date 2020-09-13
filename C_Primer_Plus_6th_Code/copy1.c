/* copy1.c -- ÑÝÊ¾strcpy */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128
#define LIM 10

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int len;
    int i = 0, count = 0;

    printf ("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && ( len = read_line_file(temp, 80, stdin) ) > 0)
    {
        if (temp[0] != 'q')
        {
            printf ("%s doesn't begin with q!\n", temp);
        }
        else
        {
            strcpy (qwords[i], temp);
             i++;
            count++;
        }
    }
    puts ("Here are the words accepted:\n");
    for (i = 0; i < count; i++)
    {
        puts (qwords[i]);
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
