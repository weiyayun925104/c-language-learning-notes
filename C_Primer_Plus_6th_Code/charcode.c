/* charcode.c - 显示字符的代码编号 */
#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;

    printf ("Please enter a character: ");
    scanf ("%c", &ch);   /* 用户输入字符 */
    printf ("The code for %c is %d.\n", ch, ch);

    return 0;
}
