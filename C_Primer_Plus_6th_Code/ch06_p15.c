#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_char (FILE *fp)
{
    int ch = getc(fp);
    if (ch == '\n' || ch == '\t')
    {
        return ' ';
    }
    return ch;
}
void read_word(char *word, int len, FILE *fp)
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

int main(int argc, char **argv)
{
    int i = 0;
    char a[256];

    printf("Please enter a line of input:\n");
    i = read_line_file(a, 255, stdin);
    if (i > 0)
    {
        while (i > 0)
        {
            printf("%c", a[i - 1]);
            i--;
        }
        printf("\n");
    }
    printf("Done!\n");

    return 0;
}
