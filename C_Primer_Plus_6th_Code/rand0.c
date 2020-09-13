/* rand0.c -- 生成随机数 */
static unsigned long int next = 1UL;

unsigned int rand0 (void)
{
    next = next * 1103515245 + 12345;

    return (unsigned int) (next / 65536) % 32768;
}
