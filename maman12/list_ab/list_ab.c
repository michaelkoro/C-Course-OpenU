/*
 * A program that receives a list of unlimited characers, prints them in an organized order.
 * After that, the program counts and prints the number of characters that were received,
 * and the number of alpha-numeric characters.
 */
#include "list_ab.h"

int main()
{
    /*
     * Solution: We start by dynamically allocating a char array of 10 cells, and start scanning for input.
     * once the input reaches the final cell of the array, we multiply the size of the array, until there is no more input.
     * We then print the received input 10 characters at a time.
     * Finally, we print the number of the received characters (which is the size of the array), and the number of alpha-numeric characters
     */
    char single_char;                                              /* Stores the recived character, one at a time */
    int size_counter = 1;                                          /* Multiplication size for dynamically allocating size for the array*/
    int arr_index = 0;                                             /* Index for the loop */
    char *char_inputs = (char *)malloc(ARRAY_MULTIPLICATION_SIZE); /* Pointer that will point to the array of characters */
    /* Checking if allocation failed. if it did, we exit */
    if (char_inputs == NULL)
    {
        printf("Memory allocation failed. Exiting\n");
        return -1;
    }
    /* Initializing an empty array */
    *char_inputs = '\0';

    printf("Please insert characters. Please note that the enter key is also a valid input. CTRL +D will stop input.\n");
    /* Scanning for input */
    while (scanf("%c", &single_char) != EOF)
    {
        /* Checking if we had reached the end of the array */
        if (arr_index % ARRAY_MULTIPLICATION_SIZE == PRINT_LIMIT_IN_LINE - 1)
        {
            /* Re-allocating memory accordingly */
            size_counter++;
            char_inputs = (char *)realloc(char_inputs, ARRAY_MULTIPLICATION_SIZE * size_counter);
            /* Checking if allocation failed. if it did, we exit */
            if (char_inputs == NULL)
            {
                printf("Memory allocation failed. Exiting\n");
                return -1;
            }
        }
        /* Adding the received character into the array of strings */
        char_inputs[arr_index] = single_char;
        arr_index++;
        /* Marking the end of the string, until the next character is received. This way we avoid having garbage in our char array */
        char_inputs[arr_index] = '\0';
    }
    print_chars(char_inputs);                                                                       /* "Pretty" printing the input characters */
    printf("Number of alpha-numeric characters in your input is : %d\n", count_alnum(char_inputs)); /* Printing number of alpha-numeric characters */
    printf("Nubmer of charactes in your input is: %d\n", arr_index);                                /* Printing the number of all the characters */
    free(char_inputs);                                                                              /* Freeing the allocated memory for the characters array */
    return 0;                                                                                       /* End */
}
/* Print function for the array */
void print_chars(char *string_input)
{
    /*
     * Solution - Running over the sring and printing all characters
     */
    int index = 0;
    printf("\nYou have inserted the following input:\n");
    while (string_input[index] != '\0')
    {
        if (index % PRINT_LIMIT_IN_LINE == 0) /* If we printed 10 characters in a single line, we need a new line */
            printf("\n----------\n");
        printf("%c", string_input[index]);
        index++;
    }
    printf("\n");
}
/* Function that counts and returns the number of alpha-numeric characters in our input */
int count_alnum(char *string_input)
{
    /*
     * Soluion - Running over the string and counting each alpha-numeric character
     */
    int index = 0, alnum_counter = 0;
    while (string_input[index] != '\0')
    {
        if (isalnum(string_input[index]))
            alnum_counter++;
        index++;
    }
    return alnum_counter;
}