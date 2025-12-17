#include <stdint.h>
#include <stdio.h>

void printBinary(uint8_t n)
{
    uint8_t mask = 0x80;
    while (mask)
    {
        printf("%d", (n & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

int main(void)
{
    uint8_t reg = 0x2A;   

  
    reg = reg | (1 << 4);
    printf("After setting bit 4:\n");
    printf("Hex = 0x%02X\n", reg);
    printf("Binary = ");
    printBinary(reg);


    reg = reg & ~(1 << 1);
    printf("\nAfter clearing bit 1:\n");
    printf("Hex = 0x%02X\n", reg);
    printf("Binary = ");
    printBinary(reg);

   
    reg = reg ^ (1 << 5);
    printf("\nAfter toggling bit 5:\n");
    printf("Hex = 0x%02X\n", reg);
    printf("Binary = ");
    printBinary(reg);

    while (1)
    {
    }
}
