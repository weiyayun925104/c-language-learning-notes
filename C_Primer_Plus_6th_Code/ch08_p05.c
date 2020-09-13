#include <stdio.h>

int main(int argc, char **argv)
{
    char response;
    int guess = 50;
    int upper_limit = 101;
    int lower_limit = 1;

    printf ("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf ("Respond with a l if my guess is lower, with a h if it is higher and with a c if it is correct.\n");
    printf ("Is your number %d?\n", guess);
    while ( ( response = getchar() ) != 'c' )
    {
        if (response == 'l')
        {
            lower_limit = guess;
            guess = (upper_limit + lower_limit) / 2;
        }
        else if (response == 'h')
        {
            upper_limit = guess;
            guess = (upper_limit + lower_limit) / 2;
        }
        else
        {
            while ( getchar() != '\n' )
            {
                continue;
            }
            printf("Please enter h or l or c.\n");
            continue;
        }

        while ( getchar() != '\n' )
        {
            continue;
        }
        printf ("Well, is your number %d?\n", guess);
    }
    printf ("Your number is %d.\n", guess);

    return 0;
}
