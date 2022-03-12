/*
 * A program that recieves two numbers,
 * and calculates the number of set bits in the same position between the numbers.
 */
#include <stdio.h>

int count_bits(unsigned long first_number, unsigned long second_number);

int main()
{
    /*
     * Solution: Calculate a new number using the & operation on the two inputed numbers, and count all set bits in that number
     * using the & opertaion with 1. Rotate the calculated number to the right, until it equals zero.
     * Finally, return the number of corelating set bits between both inputed numbers.
     */
    unsigned long x = 0, y = 0;

    printf("Please enter your first number:\n");
    scanf("%lu", &x);

    printf("Please enter your second number:\n");
    scanf("%lu", &y);

    /* Calculating and printing the result */
    printf("The numbers you entered are %lu and %lu\n", x, y);
    printf("Nubmer of matching turned on bits is: %d\n", count_bits(x, y));
    return 0;
}

int count_bits(unsigned long first_number, unsigned long second_number)
{
    unsigned long resulted_bits = 0;
    int count = 0;

    /* Using the & operation, we get a number which, in binary, represents the corelating set bits between the inputed numbers */
    resulted_bits = first_number & second_number;

    while (resulted_bits > 0)
    {
        /* When running an & operation between a number and 1, we will get 1 if the last bit of the number is 1, or 0 if it's 0 */
        count += resulted_bits & 1;
        /* Removing the last bit from the resulted number */
        resulted_bits = resulted_bits >> 1;
    }
    return count;
}