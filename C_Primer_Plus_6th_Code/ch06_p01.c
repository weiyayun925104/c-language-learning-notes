#include <stdio.h>
#define SIZE 26

int main(int argc, char **argv)
{
    char lowercase[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
    {
        lowercase[i] = 'a' + i;
    }
    printf("The array contents: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%c ", lowercase[i]);
    }
    printf("\n");
    return 0;
}
