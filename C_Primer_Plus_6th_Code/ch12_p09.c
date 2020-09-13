#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);

int main(int argc, char **argv)
{
    int n;

    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    while ( getchar() != '\n')
    {
        continue;
    }

    char **ptr = (char **) malloc ( n * sizeof (char *) );
    if (ptr == NULL)
    {
        printf ("Error, memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d words now:\n", n);
    for (int i = 0; i < n; i++)
    {
        char *word = (char *) malloc ( STRLEN * sizeof (char) );
        read_word(word, 80, stdin);
        ptr[i] = word;
    }

    printf("Here are your words:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%s\n", *(ptr + j));
    }
    for (int k = 0; k < n; k++)
    {
        free( ptr[k] );
    }
    free(ptr);

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
