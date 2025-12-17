#include <stdint.h>
#include <stdio.h>

void printBinary(uint8_t n)
{
    uint8_t mask;
    for (mask = 0x80; mask > 0; mask >>= 1)
    {
        printf("%d", (n & mask) ? 1 : 0);
    }
    printf("\n");
}

int main(void)
{
    uint8_t value = 5;   // 0000 0101
    uint8_t leftResult;
    uint8_t rightResult;

    printf("Original value = %d\nBinary = ", value);
    printBinary(value);

    
    leftResult = value << 2;
    printf("\nAfter Left Shift by 2:\n");
    printf("Decimal = %d\nBinary = ", leftResult);
    printBinary(leftResult);

    
    rightResult = value >> 1;
    printf("\nAfter Right Shift by 1:\n");
    printf("Decimal = %d\nBinary = ", rightResult);
    printBinary(rightResult);

    return 0;
}
