#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    float centimeters, meters;
    float inches, feet;
    char fname[10], lname[10];
    char name[30];

    printf("Please enter your first name: ");
    scanf("%s", fname);
    printf("Please enter your last name: ");
    scanf("%s", lname);

    sprintf(name, "%s %s", lname, fname);

    printf("Please enter your height in centimeters: ");
    scanf("%f", &centimeters);

    meters = centimeters * (1.0f / 100.0f);
    inches = centimeters * (12.0f / 30.48f) ;
    feet = centimeters * (1.0f / 30.48f) ;
    printf("%s, you are %.3f meters tall.\n", name, meters);
    printf("%s, you are %.3f inches tall.\n", name, inches);
    printf("%s, you are %.3f feet tall.\n", name, feet);

    return 0;
}
