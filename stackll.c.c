/********************************************************
*                                                   	*
*	Stack using linked list 			*
*							*
********************************************************/

#include<stdio.h>
#include<stdlib.h>

struct stack			/* data structure for Stack   */
{
	int info;
	struct stack *ptr;
};


struct stack* push (struct stack*, int);	/* function to insert an element into stack  */

struct stack * pop (struct stack*);		/* function to delete an element from stack  */

void display_list (struct stack *);		/* function to traverse (print) stack 	*/

main()
{
	struct stack *top = NULL;
	int choice, value;

	do
	{
		printf ("\n\nEnter the choice\n");
		printf ("1. Push\n2. Pop\n3. Display Stack\n4. Quit\n");

		scanf ("%d",&choice);
	
		switch (choice)
		{
			case 1:
				printf ("Enter the data to be added\n");
				scanf ("%d",&value);
				top = push (top, value);		

				break;

			case 2:
				top = pop (top);
				break;

			case 3:
				display_list(top);
				break;

			case 4:
				break;
		}

	}while (choice!=4);
}


struct stack * push (struct stack * start , int data)
{
	struct stack* new_node; 
		
	new_node = (struct stack*) malloc (sizeof(struct stack));
	new_node->info = data;
		
	new_node->ptr = start;
	start = new_node;
	printf ("Data %d enetered into stack\n",data);
	
	
	return start;
}


struct stack * pop (struct stack * start)
{
	struct stack *cur_node;

	if (start == NULL)
	{
		printf("Stack is empty\n");
		return start;
	}

	cur_node = start;

	start = start->ptr;
	free(cur_node);
	
	
	return start;

}

void display_list (struct stack *start)
{
	if (start == NULL)
	{
		printf("HI providing empty list?!!!!!!!!\n");
		return;
	}
	printf ("Elements in the list\n");
	while (start!=NULL)
	{
		printf ("%d\t",start->info);
		start = start->ptr;
	}
	printf("\n");
}
