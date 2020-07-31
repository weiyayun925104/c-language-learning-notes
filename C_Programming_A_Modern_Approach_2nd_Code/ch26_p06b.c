#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t cur = time(NULL);
    struct tm *p;
    char s[64];

    p = localtime(&cur);
    strftime(s, sizeof(s), "%a, %d %b %y  %H:%M", p);
    printf("%s\n", s);
    return 0;
}
