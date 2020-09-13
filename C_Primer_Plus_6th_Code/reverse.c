/* reverse.c -- 倒序显示文件的内容 */

#include <stdio.h>
#include <stdlib.h>

#define CTRL_Z '\032'
#define STRLEN 128

int main(int argc, char **argv)
{
    FILE *fp;
    long count, last;
    char ch;
    char file[STRLEN] = {0};

    puts ("Enter the name of the file to be processed:");
    scanf ("%80s", file);
    if ( ( fp = fopen (file, "rb") ) == NULL )
    {
        printf ("Can not open input file \"%s\"\n", file);
        exit (EXIT_FAILURE);
    }
    fseek (fp, 0L, SEEK_END);
    last = ftell (fp);
    for (count = 1L; count <= last; count++)
    {
        fseek (fp, -count, SEEK_END);
        ch = getc (fp);
        if ( ch != CTRL_Z && ch != '\r' )
        {
            putchar (ch);
        }
    }
    putchar ('\n');
    fclose (fp);

    return 0;
}
