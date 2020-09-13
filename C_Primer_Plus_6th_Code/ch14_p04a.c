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

void printing(struct identity array[]);

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

    printing(array);

    return 0;
}

void printing(struct identity array[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strlen(array[i].handle.middle_name) > 0)
        {
            printf("%s, %s %c. -- %s\n", array[i].handle.last_name, array[i].handle.first_name, array[i].handle.middle_name[0], array[i].number);
        }
        else
        {
            printf("%s, %s -- %s\n", array[i].handle.last_name, array[i].handle.first_name, array[i].number);
        }
    }
}
