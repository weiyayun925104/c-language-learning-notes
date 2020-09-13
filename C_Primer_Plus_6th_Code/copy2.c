/* copy2.c --  π”√strcpy */

#include <stdio.h>
#include <string.h>

#define WORDS "beast"
#define SIZE 128

int main(int argc, char **argv)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;

    puts (orig);
    puts (copy);
    ps = strcpy (copy + 7, orig);
    puts (copy);
    puts (ps);

    return 0;
}
