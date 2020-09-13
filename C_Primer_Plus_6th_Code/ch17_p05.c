#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    Stack s;
    char temp[STRLEN];
    int i;
    int len;
    
    s = stack_create ();
    printf("Enter a string: \n");
    while ( ( len = read_line_file(temp, 80, stdin) ) > 0 )
    {
        for (i = 0; i < len; i++)
        {
            stack_push(s, temp[i]);
        }
        for (i = 0; i < len; i++)
        {
            putchar ( stack_pop(s) );
        }
        putchar('\n');
        printf("Enter a string: \n");
    }
    stack_destroy(s);
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
