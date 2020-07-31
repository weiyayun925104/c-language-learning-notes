#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 20

int compare_words(const void *w1, const void *w2);
void *my_malloc(size_t bytes);
int read_line (char str[], int n);

int main(int argc, char **argv)
{
    char **words = NULL, *word = NULL;
    int i, max_words = 8, num_words = 0;

    words = my_malloc( max_words * sizeof(char *) );

    for (i = 0; ; i++)
    {
        word = my_malloc( (WORD_LEN + 1) * sizeof(char) );
        printf("Enter a word: ");
        read_line (word, WORD_LEN);
        if (word[0] == '\0')
        {
            break;
        }

        *(words + i) = word;
        num_words++;

        if (max_words == num_words)
        {
            char **newwords = NULL;
            int max = (max_words * 2);
            if ( ( newwords = realloc(words, sizeof(char *) * max ) ) == NULL )
            {
                printf("Error: realloc failed\n");
                exit(EXIT_FAILURE);
            }
            words = newwords;
            max_words = max;
        }
    }

    qsort(words, num_words, sizeof(char *), compare_words);
    printf("\nIn sorted order: ");

    for (i = 0; i < num_words; i++)
    {
        printf("%s", *(words + i));
        if (i < num_words - 1)
        {
            putchar(' ');
        }
    }
    printf("\n");
}

int read_line (char str[], int n)
{
    int ch, i = 0;
    ch = getchar();
    while ( ch != '\n' && ch != EOF)
    {
        if (i < n)
        {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

void *my_malloc(size_t bytes)
{
    void *p;
    if ( ( p = malloc( bytes ) ) == NULL )
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

int compare_words(const void *w1, const void *w2)
{
    return strcmp( (*(char **)w1), (*(char **)w2) );
}
