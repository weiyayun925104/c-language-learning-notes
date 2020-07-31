#include <stdio.h>

union {
    float value;
    struct float_value {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } field;
} f;

int main(int argc, char **argv)
{
    f.field.sign = 1;
    f.field.exponent = 128;
    f.field.fraction = 0;

    printf("%.1f\n", f.value);
    f.value = 176.0625;
    printf("%x\n%x\n%x\n", f.field.sign, f.field.exponent, f.field.fraction );
    return 0;
}
