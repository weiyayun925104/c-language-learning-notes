/* fgets1.c --  π”√fgets∫Õfputs */

#include <stdio.h>

#define STRLEN 14

int main(int argc, char **argv)
{
    char words[STRLEN];

    puts ("Enter a string, please.");
    fgets (words, STRLEN, stdin);
    printf ("Your string twice:\n");
    puts (words);
    fputs (words, stdout);
    puts ("Enter another string, please.");
    fgets (words, STRLEN, stdin);
    printf ("Your string twice:\n");
    puts (words);
    fputs (words, stdout);
    puts ("Done.");

    return 0;
}
