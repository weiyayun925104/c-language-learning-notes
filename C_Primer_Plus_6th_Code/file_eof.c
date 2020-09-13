// file_eof.c -- ��һ���ļ�����ʾ���ļ�

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
