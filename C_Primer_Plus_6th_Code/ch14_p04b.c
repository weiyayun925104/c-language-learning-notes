#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct name {
    char first_name[32];
    char middle_name[32];
    char last_name[32];
};

struct identity {
    char number[32];
    struct name handle;
};

void printing(char number[], char first_name[], char middle_name[], char last_name[]);

int main(int argc, char **argv)
{
    struct identity array[5] = 
    {
        {"302039823", {"Flossie", "Malan", "Dribble"}},
        {"001", {"YaYun", "", "Wei"}},
        {"002", {"Hello", "", "Wei"}},
        {"003", {"Stephen", "", "Wei"}},
        {"004", {"Polly", "", "Wei"}}
    };

    for (int i = 0; i < 5; i++)
    {
        printing(array[i].number, array[i].handle.first_name, array[i].handle.middle_name, array[i].handle.last_name);
    }

    return 0;
}

void printing(char number[], char first_name[], char middle_name[], char last_name[])
{
    if (strlen(middle_name) > 0)
    {
        printf("%s, %s %c. -- %s\n", last_name, first_name, middle_name[0], number);
    }
    else
    {
        printf("%s, %s -- %s\n", last_name, first_name, number);
    }
}
