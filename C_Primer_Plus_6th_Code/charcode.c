/* charcode.c - ��ʾ�ַ��Ĵ����� */
#include <stdio.h>

int main(int argc, char **argv)
{
    char ch;

    printf ("Please enter a character: ");
    scanf ("%c", &ch);   /* �û������ַ� */
    printf ("The code for %c is %d.\n", ch, ch);

    return 0;
}
