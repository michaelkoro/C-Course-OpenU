/* Icluding standard built-in C libraries */
#include <stdio.h>
#include <stdlib.h>

/* Max number of characters in a single node in the list */
#define CHARS_IN_LINE 50

/* The node object, consists of a char array that stores the string from the file,
 * and a pointer to another node - allowing us to create a linked list of nodes
 */
struct t_node
{
    char val[CHARS_IN_LINE];
    struct t_node *next;
};

/* Function declarations - One to create a new node, and one to print the contents of all nodes in a list */
struct t_node *node_init();
void print_t_node(struct t_node *start);