#include <stdio.h>

int count1bit(unsigned int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(void)
{
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    int result = count1bit(num);

    printf("Number of 1 bits = %d\n", result);

    return 0;
}

