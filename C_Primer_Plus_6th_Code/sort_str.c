/* sort_str.c -- ¶ÁÈë×Ö·û´®£¬²¢ÅÅÐò×Ö·û´® */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128
#define LIM 20

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void stsrt (char * strings[], int num);

int main(int argc, char **argv)
{
    char input[LIM][SIZE];
    char * ptstr[LIM];
    int count = 0;
    int len;
    int k;

    printf ("Enter up to %d lines, and I will sort them.\n", LIM);
    printf ("To stop, press the Enter key at a line's start.\n");
    while ( count < LIM &&  ( len = read_line_file(input[count], 80, stdin) ) > 0 )
    {
        ptstr[count]= input[count];
        count++;
    }
    stsrt (ptstr, count);
    puts ("\nHere's the sorted list:\n");
    for (k = 0; k < count; k++)
    {
        puts (ptstr[k]);
    }

    return 0;
}
void stsrt (char * strings[], int num)
{
    char * temp;
    int i, j;

    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if ( strcmp (strings[i], strings[j]) > 0 )
            {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
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
