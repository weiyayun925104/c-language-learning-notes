#include <stdio.h>

int main(int argc, char **argv)
{
    int guess = 1;
    char response;

    printf ("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf ("Respond with a y if my guess is right and with an n if it is wrong.\n");
    printf ("Is your number %d?\n", guess);
    while ( ( response = getchar() ) != 'y')
    {
        if (response == 'n')
        {
            printf ("Well, is your number %d?\n", ++guess);
        }
        else
        {
            printf ("please enter y or n.\n");
        }
        while (getchar() != '\n')
        {
            continue;
        }
    }
    printf ("Your number is %d.\n", guess);

    return 0;
}
