#include <stdio.h>

void printBinary4(unsigned int n)
{
    unsigned int mask;
    for (mask = 0x8; mask > 0; mask >>= 1)
        printf("%u", (n & mask) ? 1 : 0);
    printf("\n");
}

int main(void)
{
    unsigned int reg = 0xABCD;
    unsigned int lower4;
    unsigned int upper4_lowerByte;

    
    lower4 = reg & 0x000F;

    
    upper4_lowerByte = (reg & 0x00F0) >> 4;

    printf("Register = 0x%X\n\n", reg);

    printf("Lower 4 bits:\n");
    printf("Hex = 0x%X\nBinary = ");
    printBinary4(lower4);

    printf("\nUpper 4 bits of lower byte:\n");
    printf("Hex = 0x%X\nBinary = ");
    printBinary4(upper4_lowerByte);

    return 0;
}
