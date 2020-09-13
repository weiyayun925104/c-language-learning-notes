#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

char *string_in(char *s1, char *s2);

int main(int argc, char **argv)
{
    char orig[STRLEN] = "transportation";
    char *find;

    puts(orig);
    find = string_in(orig, "port");
    if (find != NULL)
    {
        puts(find);
    }
    else
    {
        puts("Not found");
    }
    find = string_in(orig, "part");
    if (find != NULL)
    {
        puts(find);
    }
    else
    {
        puts("Not found");
    }

    return 0;
}

char *string_in(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int tries;
    int nomatch = 1;

    if(l1 < l2)
    {
        return NULL;
    }
    tries = l1 + 1 - l2;
    while ( tries > 0 && ( nomatch = strncmp(s1, s2, l2) ) != 0 )
    {
        s1++;
        tries--;
    }
    if ( tries > 0 && nomatch == 0)
    {
        return s1;
    }
    else
    {
        return NULL;
    }
}
