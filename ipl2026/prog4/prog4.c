#include <stdio.h>

struct Bitfield
{
    unsigned int firstbit  : 1;
    unsigned int secondbit : 2;
    unsigned int thirdbit  : 3;
    unsigned int fourthbit : 4;
};

void printBits(unsigned int n)
{
    int i;

    for(i = 31; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);

        if(i % 8 == 0)
        {
            printf(" ");
        }
    }

    printf("\n");
}

int main()
{
    struct Bitfield a;

    a.firstbit = 1;
    a.secondbit = 2;
    a.thirdbit = 5;
    a.fourthbit = 10;

    printf("Bitfield Values\n");

    printf("firstbit  = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);
    printf("thirdbit  = %u\n", a.thirdbit);
    printf("fourthbit = %u\n", a.fourthbit);

    printf("\nSize of structure = %zu bytes\n", sizeof(a));

    unsigned int *ptr;

    ptr = (unsigned int *)&a;

    printf("\nBinary Representation:\n");

    printBits(*ptr);

    return 0;
}