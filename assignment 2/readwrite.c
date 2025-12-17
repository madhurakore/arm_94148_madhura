#include <stdint.h>
#include <stdio.h>

void printBinary8(uint8_t n)
{
    uint8_t mask;
    for (mask = 0x80; mask > 0; mask >>= 1)
        printf("%d", (n & mask) ? 1 : 0);
    printf("\n");
}

int main(void)
{
    uint8_t status = 0x08;   // 0000 1000

    printf("Status value:\n");
    printf("Hex = 0x%02X\nBinary = ", status);
    printBinary8(status);

    if (status & 0x08)   
    {
        printf("\nBit 3 is SET\n");
    }
    else
    {
        printf("\nBit 3 is CLEAR\n");
    }

    return 0;
}
