#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char fname[10], lname[10];

    printf("Please enter your first name: ");
    scanf("%s", fname);
    printf("Please enter your last name: ");
    scanf("%s", lname);

    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", strlen(fname), strlen(fname), strlen(lname), strlen(lname));
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d\n", strlen(fname), strlen(fname), strlen(lname), strlen(lname));

    return 0;
}
