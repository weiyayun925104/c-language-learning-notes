// cypher1.c -- �������룬�ո񲻱�

#include <stdio.h>

#define SPACE ' '

int main(int argc, char **argv)
{
    char ch;

    ch = getchar();
    while (ch != '\n')
    {
        if (ch == SPACE)
        {
            putchar(ch);
        }
        else
        {
            putchar (ch + 1);
        }
        ch = getchar();
    }
    putchar(ch);

    return 0;
}
