#include <stdio.h>

void chline(char ch, int i, int j);

int main(int argc, char **argv)
{
    char ch;
    int i, j;

    printf("Please enter ch, i, j:\n");
    ch = getchar();
    scanf("%d %d", &i, &j);
    chline(ch, i, j);
    printf("\n");

    return 0;
}

void chline(char ch, int i, int j)
{
    int k;

    for (k = 0; k < i; k++)
    {
        putchar(' ');
    }
    for (k = i; k <= j; k++)
    {
        putchar(ch);
    }
}
