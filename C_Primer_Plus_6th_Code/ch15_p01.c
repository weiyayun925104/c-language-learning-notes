#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

unsigned long bstr_to_dec(const char * str);
bool check_val(const char * str);

int main(int argc, char **argv)
{
    int len;
    const size_t STRLEN = CHAR_BIT * sizeof(unsigned long) + 1;
    char value[STRLEN];

    printf("Enter a binary number with up to %zu digits:\n", STRLEN - 1);
    while ( ( len = read_line_file(value, STRLEN - 1, stdin) ) > 0 )
    {
        if ( !check_val(value) )
        {
            printf ("Error, A binary number contains just 0 and 1.\n");
        }
        else
        {
            printf("%s is %lu\n", value, bstr_to_dec(value) );
        }
        printf("Enter a binary number with up to %zu digits:\n", STRLEN - 1);
    }
    printf ("Done.\n");

    return 0;
}

unsigned long bstr_to_dec(const char * str)
{
    unsigned long val = 0;

    while (*str)
    {
        val = 2 * val + ( (*str) - '0');
        str++;
    }

    return val;
}
bool check_val(const char * str)
{
    while (*str)
    {
        if (*str != '0' && *str != '1')
        {
            return false;
        }
        str++;
    }

    return true;
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
