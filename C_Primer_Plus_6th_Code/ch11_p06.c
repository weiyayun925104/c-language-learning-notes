#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

bool is_within(const char *str, char c);

int main(int argc, char **argv)
{
    char input[STRLEN];
    char ch;
    int len;
    int found;

    printf("Enter a string: ");
    while ( ( len = read_line_file(input, 80, stdin) ) > 0 )
    {
        printf("Enter a character: ");
        ch = getchar();
        while (getchar() != '\n')
        {
            continue;
        }
        found = is_within(input, ch);
        if (found == false)
        {
            printf("%c not found in string.\n", ch);
        }
        else
        {
            printf("%c found in string %s\n", ch, input);
        }
        printf("Enter a string: ");
    }
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
bool is_within(const char *str, char ch)
{
    while (*str != ch && *str != '\0')
    {
        str++;
    }
    if (*str == '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}
