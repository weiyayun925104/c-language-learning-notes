#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;
    int num_space = 0;
    int num_newline = 0;
    int num_other = 0;

    printf("Please enter your characters: ");
    while ( ( ch = getchar() ) != '#' )
    {
        if (ch == ' ')
        {
            num_space++;
        }
        else if (ch == '\n')
        {
            num_newline++;
        }
        else
        {
            num_other++;
        }
    }

    printf("The number of spaces read is %d.\n", num_space);
    printf("The number of newline characters read is %d.\n", num_newline);
    printf("The number of other characters read is %d.\n", num_other);

    return 0;
}
