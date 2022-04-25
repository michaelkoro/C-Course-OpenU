/* Icluding standard built-in C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Limit of characters in line - for the print function */
#define PRINT_LIMIT_IN_LINE 10
/* Default size of the array, will be nultiplied by an incrementing counter when size limit is reached */
#define ARRAY_MULTIPLICATION_SIZE 10

/* Function declarations - one for printing the input, and one for counting alpha-numeric characters */
void print_chars(char string_input[]);
int count_alnum(char string_input[]);