#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

char *vstrcat(const char *first, ...);

int main(int argc, char **argv)
{
    char *str;

    str = vstrcat("Special", "Agent", "Dale", "Cooper", NULL);
    if (str != NULL)
    {
        printf("%s\n", str);
        free(str);
    }
    return 0;
}

char *vstrcat(const char *first, ...)
{
    va_list ap;
    char *res, *p;
    int len = 0;

    if ( first != ( (char *) NULL ) )
    {
        len += strlen(first);
    }
    va_start(ap, first);
    while ( ( p = va_arg(ap, char *) ) != ( (char *) NULL ) )
    {
        len += strlen(p);
    }
    if (len < 1)
    {
        va_end(ap);
        return NULL;
    }
    if ( ( res = malloc(len + 1) ) == NULL )
    {
        va_end(ap);
        return NULL;
    }
    va_end(ap);

    if ( first != ( (char *) NULL ) )
    {
        strcpy(res, first);
    }
    else
    {
        res[0] = '\0';
    }
    va_start(ap, first);
    while ( ( p = va_arg(ap, char *) ) != ( (char *) NULL ) )
    {
        strcat(res, p);
    }
    
    va_end(ap);
    return res;
}
