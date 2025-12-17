#include <stdio.h>
int main()
{
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        printf("Character is an alphabet.\n");
        ch = ch ^ 32;
        printf("Result after XOR with 32: %c\n", ch);
    }
    else
    {
        printf("Character is NOT an alphabet.\n");
    }
    return 0;
}
