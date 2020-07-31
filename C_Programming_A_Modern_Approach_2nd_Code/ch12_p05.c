#include <stdio.h>

#define MAX_VALUE 100

int main(int argc, char **argv)
{
    char c, *p, *q, terminating_char, words[MAX_VALUE] = {0};

    printf("Enter a sentence: ");
    for (p = words; (c = getchar()) != '\n' && p < words + MAX_VALUE; p++)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            terminating_char = c;
            break;
        }
        *p = c;
    }
    p--;

    printf("Reversal of sentence: ");
    if(p >= words)
    {
        while (p >= words)
        {
            while (*p == ' ' && p > words)
            {
                p--;
            }
            if(*p == ' ' && p == words)
            {
                break;
            }
            if(*p != ' ')
            {
                while (*p != ' ' && p > words)
                {
                    p--;
                }

                if(*p == ' ')
                {
                    q = p + 1;
                    while (*q != ' ' && *q != '\0')
                    {
                        putchar(*q++);
                    }
                    putchar(' ');
                }
                else
                {
                    q = words;
                    while (*q != ' ' && *q != '\0')
                    {
                        putchar(*q++);
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
