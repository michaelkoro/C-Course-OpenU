#include <stdio.h>

/*Assuming the user won't send an input of vectors larger than 100 numbers */
#define MAX_VECTOR_LENGTH 100

int scalar_product(int first_vector[], int second_vector[], int vector_length);

int main()
{
    int first_vector[MAX_VECTOR_LENGTH], second_vector[MAX_VECTOR_LENGTH];
    int length_of_vectors = 0;

    /* Initializing both arrays with zeroes */
    for (int i = 0; i < MAX_VECTOR_LENGTH; i++)
        first_vector[i] = second_vector[i] = 0;

    printf("Please enter the length of your vectors, when the max length is 100:");
    scanf("%d", length_of_vectors);

    printf("Please enter the values of the first Vector seperated by newlines:");
    for (int j = 0; j < length_of_vectors; j++)
        scanf("%d", &first_vector[j]);

    printf("Please enter the values of the second Vector seperated by newlines:");
    for (int k = 0; k < length_of_vectors; k++)
        scanf("%d", &first_vector[k]);

    printf("The Scalar Multiplication of both vectors is: %d", scalar_product(first_vector, second_vector, length_of_vectors));
}

int scalar_product(int first_vector[], int second_vector[], int vector_length)
{
    int sum_of_vectors = 0; /* Initializing the sum of vectors as 0 */
    /* Multiplying and adding correlating values */
    for (int i = 0; i < vector_length; i++)
        sum_of_vectors += first_vector[i] * second_vector[i];

    return sum_of_vectors;
}
