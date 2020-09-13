#include <stdio.h>

int main(int argc, char **argv)
{
    float Mbit, MByte;

    printf("Please enter the download speed in megabits per second: ");
    scanf("%f", &Mbit);
    printf("Please enter the size of a file in megabytes: ");
    scanf("%f", &MByte);

    printf("At %.2f megabits per second, a file of %.2f megabytes\n"
           "downloads in %.2f seconds.\n", Mbit, MByte, MByte / (Mbit / 8.0f) );

    return 0;
}
