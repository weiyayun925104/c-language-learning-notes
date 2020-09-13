#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char a[32];
    int index;

    printf("Please enter a single word: ");
    scanf("%s", a);
    for (index = strlen(a); index > 0; index--)
    {
        printf("%c", a[index - 1]);
    }
    printf("\n");

    return 0;
}
