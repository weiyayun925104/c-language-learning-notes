#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;
    int flag = 0;
    int count = 0;

    printf("Please enter your characters: ");
    while ( ( ch = getchar() ) != '#' )
    {
        if (ch == 'e')
        {
            flag = 1;
        }
        else if (ch == 'i' && flag == 1)
        {
            count++;
            flag = 0;
        }
        else
        {
            flag = 0;
        }
    }

    printf("The number of times that the sequence ei occurs is %d.\n", count);

    return 0;
}
