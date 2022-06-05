/*
 * A program that receives a file name as a command line argument,
 * and prints the contents of the file in an organized way where all lines are equal.
 */
#include "lists_c.h"

/* A function which creates and initializes a new node.
 * The value of the node is an empry string, and the next node it points to is set to null.
 */
struct t_node *node_init()
{
    struct t_node *ptr;
    /* Allocating memory for the new node */
    ptr = (struct t_node *)malloc(sizeof(struct t_node));

    /* Checking if the memory allocation was succesful */
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    /* Initializing an empty array of characters and a null pointer */
    *(ptr->val) = '\0';
    ptr->next = NULL;

    return ptr;
}

/* A function that iterates over the list of nodes and prints the values inside every node */
void print_t_node(struct t_node *start)
{
    /* Initializing a tmp pointer to the list, that way the original pointer that was sent will be unchanged */
    struct t_node *index = start;

    /* Iterating over the list */
    while (index != NULL)
    {
        puts(index->val);
        index = index->next; /* Advancing in the list to the next node */
    }
}

int main(int argc, char *argv[])
{

    /*
     * Solution: We Check if there was a command line argument when executing the program -
     * If not, we exit the program as there is no file to read from. Otherwise, we continue and open the named file, with read permissions.
     * If we are unable to open the file, we'll exit the program.
     * Otherwise, we'll start reading up to 50 characters at a time from the file (Or until a new line), and storing them in the linked list.
     * Once the reading process is complete, we iterate over the linked list and print all the characters that were stored in it.
     */
    FILE *file_pointer;                        /* file pointer that will be used to read from the file */
    struct t_node *root = NULL, *index = NULL; /* Defining pointers for the linked list of nodes */

    /* If the user passed more than one argument, or no argument at all, we exit the program */
    if (argc != 2)
    {
        printf("One argument is required - File name\n");
        exit(2);
    }
    /* Attempting to open the file given by the user*/
    file_pointer = fopen(argv[1], "r");

    /* If there was an issue opening the given file, we exit the program */
    if (file_pointer == NULL)
    {
        printf("Could not read file\n");
        exit(3);
    }
    /* Initializing an empty linked list of nodes */
    root = node_init();
    index = root;
    /* Reading the contents of the file, and storing them in the current node in the list */
    while (fgets(index->val, CHARS_IN_LINE, file_pointer))
    {
        /* Creating a new node and adding it to the list */
        index->next = node_init();
        /* Advancing in the list */
        index = index->next;
    }

    /* Closing the file as we finished reading from it */
    fclose(file_pointer);
    /* Printing everything in the list */
    print_t_node(root);

    return 0;
}