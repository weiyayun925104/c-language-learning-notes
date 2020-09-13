#include <stdio.h>

int main(int argc, char **argv)
{
    int row, space;
    char ch, ch1;

    printf("Please enter an uppercase letter: ");
    scanf("%c", &ch1);

    for (row = 0; row < ch1 - 'A' + 1; row++)
    {
        for (space = 0; space < ch1 - 'A' - row; space++)
        {
            printf(" ");
        }
        for (ch = 'A'; ch < 'A' + row + 1; ch++)
        {
            printf("%c", ch);
        }
        for (ch = 'A' + row - 1; ch >= 'A'; ch--)
        {
            printf("%c", ch);
        }

        printf("\n");
    }

    return 0;
}
