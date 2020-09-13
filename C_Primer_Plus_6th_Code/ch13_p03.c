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
    int ch;
    int len;
    char sourcefile[STRLEN];
    char targetfile[STRLEN];
    FILE * source;
    FILE * target;

    printf("Please enter the name of a text file to act as the source file: ");
    len = read_line_file(sourcefile, 80, stdin);
    if (len <= 0)
    {
        fprintf(stderr, "filename invalid\n");
        exit(EXIT_FAILURE);
    }
    printf("Please enter the name of a text file to act as the output file: ");
    len = read_line_file(targetfile, 80, stdin);
    if (len <= 0)
    {
        fprintf(stderr, "filename invalid\n");
        exit(EXIT_FAILURE);
    }

    if ( ( source = fopen(sourcefile, "r") ) == NULL )
    {
        fprintf(stderr, "Could not open file %s for input\n", sourcefile);
        exit(EXIT_FAILURE);
    }

    if ( ( target = fopen(targetfile, "w") ) == NULL )
    {
        fclose (source);
        fprintf(stderr, "Could not open file %s for output\n", targetfile);
        exit(EXIT_FAILURE);
    }

    while ( ( ch = getc(source) ) != EOF )
    {
        if ( islower(ch) )
        {
            ch = toupper(ch);
        }
        putc(ch, target);
    }

    if (fclose(source) != 0)
    {
        printf("Could not close file %s\n", sourcefile);
    }
    if (fclose(target) != 0)
    {
        printf("Could not close file %s\n", targetfile);
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
