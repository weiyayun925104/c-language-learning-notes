#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char fname[10], lname[10];
    char name[30];

    printf("Please enter your first name: ");
    scanf("%s", fname);
    printf("Please enter your last name: ");
    scanf("%s", lname);

    sprintf(name, "%s, %s", lname, fname);

    printf("Your name is \"%s\".\n", name);
    printf("Your name is \"%20s\".\n", name);
    printf("Your name is \"%-20s\".\n", name);
    printf("Your name is \"%*s\".\n", strlen(name)+3, name);

    return 0;
}
