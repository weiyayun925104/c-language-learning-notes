#include <stdio.h>

#define MAX_VALUE 100

int main(int argc, char **argv)
{
    int i = 0, j;
    char c, terminating_char = 0, words[MAX_VALUE] = {0};

    printf("Enter a sentence: ");
    for (i = 0; (c = getchar()) != '\n' && i < MAX_VALUE; i++)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            terminating_char = c;
            break;
        }
        words[i] = c;
    }
    i--;
    printf("Reversal of sentence: ");
    if(i >= 0)
    {
        while (i >= 0)
        {
            while (words[i] == ' ' && i > 0)
            {
                i--;
            }
            if(words[i] == ' ' && i == 0)
            {
                break;
            }
            if(words[i] != ' ')
            {
                while (words[i] != ' ' && i > 0)
                {
                    i--;
                }

                if(words[i] == ' ')
                {
                    j = i + 1;
                    while (words[j] != ' ' && words[j] != '\0')
                    {
                        putchar(words[j++]);
                    }
                    putchar(' ');
                }
                else
                {
                    j = 0;
                    while (words[j] != ' ' && words[j] != '\0')
                    {
                        putchar(words[j++]);
                    }
                    putchar(' ');
                    break;
                }
            }
        }
    }
    if(terminating_char != 0)
    {
        printf("\b%c\n", terminating_char);
    }
    return 0;
}
