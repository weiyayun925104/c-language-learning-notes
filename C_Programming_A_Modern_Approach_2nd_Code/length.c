/* Determines the length of a message */

#include<stdio.h>

int main(int argc, char **argv)
{
    char ch;
    int len = 0;
    printf ("Enter a message: ");
    ch = getchar();
    while (ch != '\n')
    {
        len++;
        ch = getchar();
    }
    printf ("your message was %d character(s) long.\n", len);
    return 0;
}
