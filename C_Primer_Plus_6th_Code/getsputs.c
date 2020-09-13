/* getsputs.c --  π”√gets∫Õputs */

#include <stdio.h>

#define STRLEN 81

int main(int argc, char **argv)
{
    char words[STRLEN];

    puts ("Enter a string, please.");
    gets (words);
    printf ("Your string twice:\n");
    printf ("%s\n", words);
    puts (words);
    puts ("Done.");

    return 0;
}
