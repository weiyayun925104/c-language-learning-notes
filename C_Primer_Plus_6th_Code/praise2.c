/* praise2.c */

#include <stdio.h>
#include <string.h>

#define PRAISE "You are an extraordinary being."

int main(int argc, char **argv)
{
    char name[40];

    printf ("What's your name? ");
    scanf ("%s", name);
    printf ("Hello, %s. %s\n", name, PRAISE);
    printf ("Your name of %zu letters occupies %zu memory cells.\n", strlen(name), sizeof(name) );
    printf ("The phrase of praise has %zu letters", strlen(PRAISE) );
    printf ("and occupies %zu memory cells.\n", sizeof(PRAISE) );

    return 0;
}
