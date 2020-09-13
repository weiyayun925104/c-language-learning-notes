/* s_and_r.c -- ����rand1��srand1���ļ� */

static unsigned long int next = 1UL;

unsigned int rand1 (void)
{
    next = next * 1103515245 + 12345;

    return (unsigned int) (next / 65536) % 32768;
}
void srand1 (unsigned long int seed)
{
    next = seed;
}