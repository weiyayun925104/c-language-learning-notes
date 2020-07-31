/* Tests the case-mapping functions */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char *p;
    for (p = "azAZ0!"; *p != '\0'; p++)
    {
        printf ("tolower('%c') is '%c'; ", *p, tolower(*p) );
        printf ("toupper('%c') is '%c'\n", *p, toupper(*p) );
    }
    return 0;
}
