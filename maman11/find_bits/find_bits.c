#include <stdio.h>

int count_bits(unsigned long first_number, unsigned long second_number);

int main()
{
    unsigned long x = 0, y = 0;

    printf("Please enter your first number:\n");
    scanf("%lu", &x);

    printf("Please enter your second number:\n");
    scanf("%lu", &y);

    printf("Nubmer of matching turned on bits is: %d\n", count_bits(x, y));
    return 0;
}

int count_bits(unsigned long first_number, unsigned long second_number)
{
    unsigned long resulted_bits = 0;
    int count = 0;
    resulted_bits = first_number & second_number;
    while (resulted_bits > 0)
    {
        count += resulted_bits & 1;
        resulted_bits = resulted_bits / 2;
    }
    return count;
}