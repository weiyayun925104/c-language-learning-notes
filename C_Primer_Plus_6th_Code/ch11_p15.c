#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_atoi(char *str);

int main(int argc, char **argv)
{
    int converted1 = my_atoi("5G");

    printf("%d\n", converted1);

    int converted2 = my_atoi("5");

    printf("%d\n", converted2);

    return 0;
}

int my_atoi(char *str)
{
    int answer = 0;
    int place = 1;

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if ( !isdigit( str[i] ) )
        {
            printf("The input string is not a pure number.\n");
            return 0;
        }
        answer += (str[i] - '0') * place;
        place *= 10;
    }

    return answer;
}
