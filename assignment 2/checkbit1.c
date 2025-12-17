#include <stdint.h>
#include <stdio.h>

void printBinary(uint8_t n)
{
    uint8_t mask;
    for (mask = 0x80; mask > 0; mask >>= 1)
        printf("%d", (n & mask) ? 1 : 0);
    printf("\n");
}

int main(void)
{
    uint8_t reg = 0xAA;   
    uint8_t field;

    printf("Before modification:\n");
    printf("Hex = 0x%02X\nBinary = ", reg);
    printBinary(reg);

    field = (reg >> 2) & 0x07;   
    printf("\nRead bits (2 to 4) = 0b%03d\n", field);

    
    reg = reg & ~(0x07 << 2);    
    reg = reg | (0x03 << 2);     

    printf("\nAfter modification:\n");
    printf("Hex = 0x%02X\nBinary = ", reg);
    printBinary(reg);

    return 0;
}
