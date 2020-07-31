#include <stdio.h>
#include <string.h>
#include <ctype.h>

void capitalize_all_g(char *s)
{
    char * p;
    int i, m = 0;
    int n = strlen(s);
    int pos[n];
    p = strrchr(s, 'g');
    while (p != NULL)
    {
        pos[m++] = (p - s);
        *p = '\0';
        p = strrchr(s, 'g');
    }
    for(i = 0; i < m; i++)
    {
        s[pos[i]] = 'G';
    }
    return;
}

int main(int argc, char **argv)
{
    char str[] = "We had a great day together.";
    capitalize_all_g(str);
    printf("%s\n", str);

    return 0;
}
