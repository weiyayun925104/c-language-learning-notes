/* nono.c -- 千万不要模仿! */

#include <stdio.h>

int main(int argc, char **argv)
{
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!'};
    char side_b[] = "Side B";

    puts (dont);   /* dont不是一个字符串 */

    return 0;
}
