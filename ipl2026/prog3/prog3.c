#include <stdio.h>

void printBitsInt(int n)
{
    int i;

    printf("\nBits of Integer:\n");

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

int countOneBits(int n)
{
    int count = 0;

    while(n != 0)
    {
        if(n & 1)
        {
            count++;
        }

        n = n >> 1;
    }

    return count;
}

void checkEndian()
{
    int x = 1;

    char *ptr = (char*)&x;

    printf("\nEndian Check:\n");

    if(*ptr == 1)
    {
        printf("System is Little Endian\n");
    }
    else
    {
        printf("System is Big Endian\n");
    }
}

void printFloatBits(float f)
{
    unsigned int *ptr;

    ptr = (unsigned int*)&f;

    printf("\nBits of Floating Point Number:\n");

    for(int i = 31; i >= 0; i--)
    {
        printf("%d", (*ptr >> i) & 1);

        if(i % 8 == 0)
        {
            printf(" ");
        }
    }

    printf("\n");
}

void explainNegativeInteger(int n)
{
    printf("\nNegative Integer Representation:\n");

    printf("Decimal Value = %d\n", n);

    printBitsInt(n);
}

void explainFloat(float f)
{
    unsigned int *ptr;

    ptr = (unsigned int*)&f;

    unsigned int sign;
    unsigned int exponent;
    unsigned int mantissa;

    sign = (*ptr >> 31) & 1;

    exponent = (*ptr >> 23) & 0xFF;

    mantissa = (*ptr) & 0x7FFFFF;

    printf("\nIEEE 754 Floating Point Details\n");

    printf("Float Value = %f\n", f);

    printf("Sign Bit     = %u\n", sign);

    printf("Exponent     = %u\n", exponent);

    printf("Mantissa     = %u\n", mantissa);

    printFloatBits(f);
}

int main()
{
    int n;
    float f;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printBitsInt(n);

    printf("\nNumber of 1 bits = %d\n", countOneBits(n));

    checkEndian();

    explainNegativeInteger(-n);

    printf("\nEnter a floating point number: ");
    scanf("%f", &f);

    explainFloat(f);

    printf("\nNegative Floating Point Representation:\n");

    explainFloat(-f);

    return 0;
}