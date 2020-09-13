/* for_char.c */

#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;

    for (ch = 'a'; ch <= 'z'; ch++)
    {
        printf ("The ASCII value for %c is %d.\n", ch, ch);
    }

    return 0;
}
