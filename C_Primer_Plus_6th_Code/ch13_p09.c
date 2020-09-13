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
    FILE *fp;
    int ret;
    int len;
    int wordcnt = 0;
    char words[STRLEN] = {0};

    if (argc < 2)
    {
        fprintf (stderr, "Usage: %s filename\n", argv[0]);
        exit (EXIT_FAILURE);
    }

    if ( ( fp = fopen (argv[1], "a+") ) == NULL )
    {
        fprintf (stderr, "Can not open output file \"%s\"\n", argv[1]);
        exit (EXIT_FAILURE);
    }

    rewind(fp);
    while ( ( len = read_line_file(words, 80, fp) ) > 0 )
    {
        wordcnt++;
    }

    puts ("Enter words to add to the file; press the # key at the beginning of a line to terminate.");
    while ( ( (ret = fscanf (stdin, "%40s", words) ) == 1 ) && ( words[0] != '#' ) )
    {
        fprintf (fp, "%5d %s\n", ++wordcnt, words);
    }
    fflush (fp);
    puts ("File contents:");
    rewind(fp);
    while ( ( len = read_line_file(words, 80, fp) ) > 0 )
    {
        puts (words);
    }
    puts ("Done.");
    if ( fclose (fp) != 0 )
    {
        fprintf (stderr, "Error, can not close output file.\n");
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
