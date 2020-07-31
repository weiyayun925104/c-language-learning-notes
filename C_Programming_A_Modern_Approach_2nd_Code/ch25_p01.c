#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(int argc, char **argv)
{
    char *old_locale = setlocale(LC_ALL, NULL);
    char *temp_locale = setlocale(LC_ALL, "");
    printf("Current locale\n\n%s\n\nC locale\n\n%s\n", temp_locale, old_locale);
    return 0;
}
