#include <stdio.h>


void printBinary(unsigned int n) {
    
    for (int i = 31; i >= 0; i--) {
        
        unsigned int bit = (n >> i) & 1;
        printf("%u", bit);
    }
}

int main() {
    unsigned int number;

    printf("Enter a number: ");
    scanf("%u", &number);

    printf("Binary representation: ");
    printBinary(number);
    printf("\n");

    return 0;
}

