#include <stdio.h>

int main(int argc, char **argv)
{
    char fname[10], lname[10];

    printf("Please enter your first name: ");
    scanf("%s", fname);
    printf("Please enter your last name: ");
    scanf("%s", lname);
    printf("Your name is %s, %s.\n", lname, fname);

    return 0;
}
