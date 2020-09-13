#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int ch;
    int num_of_upper = 0, num_of_lower = 0, num_of_other = 0;

    while ( ( ch = getchar() ) != EOF )
    {
        if ( isupper(ch) )
        {
            num_of_upper++;
        }
        else if ( islower(ch) )
        {
            num_of_lower++;
        }
        else
        {
            num_of_other++;
        }
    }

    printf("The number of uppercase letters is %d,\n"
           "The number of lowercase letters is %d,\n"
           "The number of other characters is %d.\n", num_of_upper, num_of_lower, num_of_other);

    return 0;
}
