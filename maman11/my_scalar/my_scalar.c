/*
 * A program that recieves two vectors and their lengh,
 * and calculates the scalar multiplication of the recieved vectors
 */
#include <stdio.h>

/*Assuming the user won't send an input of vectors larger than 100 numbers */
#define MAX_VECTOR_LENGTH 100

int scalar_product(int first_vector[], int second_vector[], int vector_length);

int main()
{
    /*
     * Solution: Looping over the vectors, and multiplying every correlating cell.
     * Adding up all cells, and when done, returning the added result.
     */

    /* Index to use for loops */
    int i;

    int first_vector[MAX_VECTOR_LENGTH], second_vector[MAX_VECTOR_LENGTH];
    int length_of_vectors = 0;

    /* Initializing both arrays with zeroes */
    for (i = 0; i < MAX_VECTOR_LENGTH; i++)
        first_vector[i] = second_vector[i] = 0;

    /* Listening for input from the user */
    printf("Please enter the length of your vectors, when the max length is 100:\n");
    scanf("%d", &length_of_vectors);

    printf("Please enter the values of the first Vector seperated by newlines:\n");
    for (i = 0; i < length_of_vectors; i++)
        scanf("%d", &first_vector[i]);

    printf("Please enter the values of the second Vector seperated by newlines:\n");
    for (i = 0; i < length_of_vectors; i++)
        scanf("%d", &second_vector[i]);

    /* Calculating and printing the result */
    printf("The Scalar Multiplication of both vectors is: %d\n", scalar_product(first_vector, second_vector, length_of_vectors));
    return 0;
}

int scalar_product(int first_vector[], int second_vector[], int vector_length)
{
    int j;

    /* Initializing the sum of vectors as 0 */
    int sum_of_vectors = 0;

    /* Multiplying and adding correlating values */
    for (j = 0; j < vector_length; j++)
        sum_of_vectors = sum_of_vectors + (first_vector[j] * second_vector[j]);

    return sum_of_vectors;
}