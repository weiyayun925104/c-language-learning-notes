#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char ch;
    unsigned long long int count = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: fline filename\n");
        exit(EXIT_FAILURE);
    }

    if ( ( fp = fopen(argv[1], "r") ) == NULL )
    {
        fprintf(stderr, "Error: %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ( ( ch = getc(fp) ) != EOF )
    {
        if (ch == '\n')
        {
            count++;
        }
    }
    fclose(fp);

    printf("Lines in %s: %llu\n", argv[1], count);
    exit(EXIT_SUCCESS);
}
