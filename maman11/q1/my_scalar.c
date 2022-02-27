#include <stdio.h>

/*Assuming the user won't send an input of vectors larger than 1024 numbers */
#define MAX_VECTOR_LENGTH 1024

int scalar_product(int first_vector[], int second_vector[], int len_of_vector)
{
    int calculated_vector[MAX_VECTOR_LENGTH]; /* Defining a calculations array */
    int sum_of_vector = 0;

    /* Emptying the newly created array */
    for (int i = 0; i < MAX_VECTOR_LENGTH; i++)
        calculated_vector[i] = 0;

    /* Multiplying correlating values */
    for (int j = 0; j < len_of_vector; j++)
        calculated_vector[j] = first_vector[j] * second_vector[j];

    /* Adding all values */
    for (int k = 0; k < len_of_vector; k++)
        sum_of_vector += calculated_vector[k];

    return sum_of_vector;
}

int main()
{
}