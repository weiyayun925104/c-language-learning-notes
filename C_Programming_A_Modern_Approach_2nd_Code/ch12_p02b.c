#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int main(int argc, char **argv)
{
    char message[MAX_LEN];
    char c, *p = message, *q;

    printf("Enter a message: ");

    while ( ( c = toupper(getchar() ) ) != '\n' && p < message + MAX_LEN)
    {
        if ( isalpha(c) )
        {
            *p++ = c;
        }
    }
    p--;

    for (q = message; q < p; q++, p--)
    {
        if (*p != *q)
        {
            printf("Not a palindrome\n");
            return 0;
        }
    }
    printf("Palindrome\n");
    return 0;
}
