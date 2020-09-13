#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    char filename[STRLEN];
    int ch;
    int len;
    int ret;
    FILE *fp;
    long position;

    puts("Enter the name of the file to be processed:");
    len = read_line_file(filename, 80, stdin);
    if (len <= 0)
    {
        fprintf(stderr, "filename invalid\n");
        exit(EXIT_FAILURE);
    }
    if ( ( fp = fopen (filename, "r") ) == NULL )
    {
        fprintf (stderr, "can not open %s\n", filename);
        exit (EXIT_FAILURE);
    }
    puts("Please enter a file position (negative or nonnumeric input to quit): ");
    while ( ( ret = scanf("%ld", &position) ) == 1 && position >= 0 )
    {
        fseek(fp, position, SEEK_SET);
        ch = getc(fp);
        while (ch != EOF && ch != '\n')
        {
            putc(ch, stdout);
            ch = getc(fp);
        }
        putchar('\n');
        puts("Please enter a file position (negative or nonnumeric input to quit): ");
    }
    fclose(fp);
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
