#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    int ch;
    double num_of_letters = 0.0, num_of_words = 0.0;
    double average;
    bool new_word = true;

    while ( ( ch = getchar() ) != EOF )
    {
        if ( ispunct(ch) )
        {
            continue;
        }
        else if ( isspace(ch) )
        {
            new_word = true;
            continue;
        }
        else
        {
            num_of_letters++;
            if (new_word)
            {
                num_of_words++;
                new_word = false;
            }
        }
    }

    average = num_of_letters / num_of_words;
    printf("The average number of letters per word is %g.\n", average);

    return 0;
}
