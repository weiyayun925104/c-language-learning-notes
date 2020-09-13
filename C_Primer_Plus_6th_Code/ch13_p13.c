#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROWS    20
#define COLS    30
#define LEVELS  10

#define STRLEN 128

const char trans[LEVELS + 1] = " .':~*=&%@";

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void MakePic(int rows, int cols, int data[rows][cols], char pic[rows][cols]);
void init(int rows, int cols, char arr[rows][cols], char ch);

int main(int argc, char **argv)
{
    int row, col;
    int picIn[ROWS][COLS];
    char picOut[ROWS][COLS];
    char fileName[STRLEN];
    FILE *infile;
    int len;

    row = ROWS;
    col = COLS;

    init(row, col, picOut, 'S');

    printf("Enter name of file: ");
    len = read_line_file(fileName, 80, stdin);
    if (len <= 0)
    {
        fprintf(stderr, "fileName invalid\n");
        exit(EXIT_FAILURE);
    }
    if ( ( infile = fopen (fileName, "r") ) == NULL )
    {
        fprintf (stderr, "can not open %s\n", fileName);
        exit (EXIT_FAILURE);
    }

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            fscanf(infile, "%d", &picIn[row][col]);
        }
    }
    if ( ferror(infile) )
    {
        fclose (infile);
        fprintf(stderr, "Error, getting data from file.\n");
        exit(EXIT_FAILURE);
    }
    MakePic(row, col, picIn, picOut);

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            putchar(picOut[row][col]);
        }
        putchar('\n');
    }

    return 0;
}

void init(int rows, int cols, char arr[rows][cols], char ch)
{
    int r, c;
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            arr[r][c] = ch;
        }
    }
}

void MakePic(int rows, int cols, int data[rows][cols], char pic[rows][cols])
{
    int row, col;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            pic[row][col] = trans[data[row][col]];
        }
    }
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
