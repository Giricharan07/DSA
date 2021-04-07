#include"stdio.h"
#include"stdlib.h"
#include<inttypes.h>
struct node{
	int data;
	struct node *npx;
};

struct node *XOR(struct node*a, struct node*b)
{
	return (struct node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(struct node *head,int data)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->npx = head;
	if(head!= NULL)
	{
		head->npx = XOR(new,(head)->npx);
	}
	head = new;
void printList (struct node *head)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
 
    printf ("Following are the nodes of Linked List: \n");
 
    while (curr != NULL)
    {
        // print current node
        printf ("%d ", curr->data);
 
        // get address of next node: curr->npx is
        // next^prev, so curr->npx^prev will be
        // next^prev^prev which is next
        next = XOR (prev, curr->npx);
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}
 
// Driver program to test above functions
int main()
{
    /* Create following Doubly Linked List
    head-->40<-->30<-->20<-->10 */
    struct node *head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
 
    // print the created list
    printList (head);
 
    return (0);
}}
