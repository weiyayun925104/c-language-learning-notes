// file_eof.c -- 打开一个文件并显示该文件

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int ch;
    FILE * fp;
    char fname[50];

    printf ("Enter the name of the file: ");
    scanf ("%s", fname);
    fp = fopen (fname, "r");
    if (fp == NULL)
    {
        printf ("Can not open file %s.\n", fname);
        exit(EXIT_FAILURE);
    }
    while ( ( ch = getc(fp) ) != EOF)
    {
        putchar(ch);
    }
    fclose (fp);

    return 0;
}
