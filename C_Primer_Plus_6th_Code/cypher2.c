// cypher2.c -- �滻�������ĸ������ĸ�ַ����ֲ���

#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char ch;

    while ( ( ch = getchar() ) != '\n' )
    {
        if ( isalpha(ch) )
        {
            putchar(ch + 1);
        }
        else
        {
            putchar(ch);
        }
    }
    putchar(ch);

    return 0;
}
