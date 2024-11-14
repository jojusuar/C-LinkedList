//Code adapted from @Leyxargon
// Original source: https://github.com/Leyxargon/c-linked-list
// Authored by @jojusuar

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct node {
	void *n;              /* data field(s) */
	/* float b;
	 * char c;
	 * ... etc.
	 */
	struct node *next;  /* pointer to next element */
}Node;

typedef struct list {
	Node *head;
	Node *tail;
	int length;
}List;

List *newList(); /* Allocates an empty list in heap memory and returns a pointer to it. */

Node *newNode( void * ); /* physically creates a new node */
/* N.B. this function is called by other functions because does not take care
 * of inserting the Node in the list, but delegates this operation to other
 * functions, such as *Insert functions */

void *get(List *, int ); /* Iterates through the list nodes until the specified index and returns the generic held by the node.*/

void headInsert(List *, void * ); /* Creates a node that holds the generic element and inserts it at the head. */

void tailInsert(List *, void * ); /* Creates a node that holds the generic element and inserts it at the tail. */

void *pop(List *, int ); /* Removes the node in the specified index and returns the generic element it held. */

Node *extractNode(List * , int ); /* Utilitary to pop(), don't use directly. */

void appendNode(List * , Node * ); /* Appends an existing node to the tail of the list. */

void appendList(List * , List * ); /* Appends the whole 2nd list to the 1st list and frees the 2nd. */

void deleteList(List *); /* Modified by José Julio Suárez */