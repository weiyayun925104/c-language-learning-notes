/* echo_eof.c -- �ظ�����, ֱ���ļ���β */

#include <stdio.h>

int main(int argc, char **argv)
{
    int ch;

    while ( ( ch = getchar() ) != EOF)
    {
        putchar(ch);
    }

    return 0;
}
