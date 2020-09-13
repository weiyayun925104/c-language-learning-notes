#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int c;
    int low_ct = 0;
    int up_ct = 0;
    int dig_ct = 0;
    int n_words = 0;
    int punc_ct = 0;
    bool inword = false;

    printf("Enter text to be analyzed (EOF to terminate):\n");
    while ( ( c = getchar() ) != EOF )
    {
        if ( islower(c) )
        {
            low_ct++;
        }
        else if ( isupper(c) )
        {
            up_ct++;
        }
        else if ( isdigit(c) )
        {
            dig_ct++;
        }
        else if ( ispunct(c) )
        {
            punc_ct++;
        }

        if (!isspace(c) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (isspace(c) && inword)
        {
            inword = false;
        }
    }
    printf("\nwords = %d, lowercase = %d, uppercase = %d, "
           "digits = %d, punctuation = %d\n", n_words, low_ct, up_ct, dig_ct, punc_ct);

    return 0;
}
