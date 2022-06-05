/*
 * A program that calls a function with a varying number of unsigned integers, which calculates the and operation on all received integers,
 * and prints them in Decimal and Hexadecimal form
 */
#include "my_and.h"

/* And operation calculation function */
unsigned int my_and(unsigned int num, ...)
{
    int i; /* Initializing the index to use for iterating over the list of arguments */
    va_list ap;
    unsigned int result = UINT_MAX;

    /* initialize ap for num number of arguments */
    va_start(ap, num);

    /* access all the arguments assigned to ap and calcuate the AND operation on all arguments*/
    for (i = 0; i < num; i++)
        result = result & va_arg(ap, unsigned int);

    /* clean memory reserved for ap */
    va_end(ap);
    return result;
}

int main()
{
    unsigned int and_result = 0;
    printf("First Call:\n");
    printf("And Operation result of the following: 112, 234, 198 is\n");
    and_result = my_and(3, 112, 234, 198);
    printf("Decimal - %u, Hex - %X\n", and_result, and_result);

    printf("Second Call:\n");
    printf("And Operation result of the following: 579, 471 is\n");
    and_result = my_and(2, 579, 471);
    printf("Decimal - %u, Hex - %X\n", and_result, and_result);

    printf("Third Call:\n");
    printf("And Operation result of the following: 4597, 7982, 4388, 7777 is\n");
    and_result = my_and(4, 4597, 7982, 4388, 7777);
    printf("Decimal - %u, Hex - %X\n", and_result, and_result);

    printf("Fourth Call:\n");
    printf("And Operation result of the following: 1 is\n");
    and_result = my_and(1, 1);
    printf("Decimal - %u, Hex - %X\n", and_result, and_result);

    return 0;
}