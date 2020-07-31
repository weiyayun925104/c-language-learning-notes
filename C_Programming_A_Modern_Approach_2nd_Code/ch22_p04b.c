#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    unsigned long long int count = 0;
    char ch;
    bool in_word = false;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: fword filename\n");
        exit(EXIT_FAILURE);
    }

    if ( ( fp = fopen(argv[1], "r") ) == NULL )
    {
        fprintf(stderr, "Error: %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ( ( ch = getc(fp) ) != EOF )
    {
        if ( !isspace(ch) )
        {
            if (!in_word)
            {
                count++;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }
    }
    fclose(fp);

    printf("Words in %s: %llu\n", argv[1], count);
    exit(EXIT_SUCCESS);
}
