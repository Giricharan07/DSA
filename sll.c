#include"stdio.h"
#include"stdlib.h"

struct node{
int data;
struct node *next;
};
struct node *head;

		
		
void ins_at_begg(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->next=head;
	head=new;
}

void ins_pos(int data,int pos)
{
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	int i;
	struct node *temp=head;
	if(pos==1)
	{
		ptr->next = temp;
		head = ptr;
		return;
	}
	for(i=1;i<pos-1;i++)  
   	{
       	temp=temp->next;
   	}
	
   	ptr->next=temp->next;  
    temp->next=ptr;
}

void display()
{
	struct node *temp=head;
	printf("List:\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d\n",i+1);        
				display(); 
				exit(0);
            }   
            else  
            {  
               ptr = ptr -> next;
            }  
            i++;               
        }
		printf("item not found\n");  
    }     
}  

void deletion_beginning()
{ 
 	if(head == NULL) 
 		printf("\n The list is Empty\n"); 

 	struct node *temp;
 	temp = head; 			//Make temp as head node
 	head = head -> next; 	// Shift the head node
 	free(temp); 			// Delete the temporary node
}

void insert_node_end(int data)
{
	struct node *newNode, *temp;
	newNode = (struct node*)malloc(sizeof(struct node));  //Allocating memory to the node
	if(newNode == NULL)
	{
		printf("Unable to allocate memory.");
	}
	else
	{
		newNode->data = data;  // Assigning data to the newNode
		newNode->next = NULL;
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
			
		temp->next = newNode;   // newNode is made as the last node
	}
}

void deletion_end()
{
	// Empty List
	if(head -> next == NULL)
	{
		free(head); 			//Delete head
		head = NULL; 			// make the reference to NULL
	}
	
	struct node *temp = head,*prev_node;
	
	while(temp -> next != NULL)
	{
		prev_node = temp;
		temp = temp -> next; 	//Traverse to to the last node
	}
	
	free(temp); 				//Delete the last node
	prev_node -> next = NULL;
}

void deletion_given_pos(int pos)
{
	// Empty List
	if(head == NULL)
	{
		free(head); 						//Delete head
		head = NULL; 						// make the reference to NULL
	}
	struct node *temp = head,*prev_node;
	int count = 0;
	while(temp -> next != NULL && pos != count)
	{
		prev_node = temp; 			 		// Tracking the (position - 1 )node
		temp = temp -> next; 
		count = count + 1;
	}
	
	if(pos == count)
	{
		prev_node -> next = temp -> next;  	// Assigning the address of the node to be deleted to its previous node
		free(temp); 						// Delete the node
	}
}
static void reverse()
{
	struct node *prev = NULL;
	struct node *current = head;
	struct node *next = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}	

int main()
{
    int i, n, pos, data;
																	  
	ins_at_begg(9);
	ins_at_begg(7);
	insert_node_end(5);
	insert_node_end(4);
	ins_at_begg(2);
	ins_at_begg(10);
	//deletion_given_pos(1);
//	ins_pos(11,1);
	//deletion_end();
	//deletion_given_pos(3)
	//deletion_beginning();
	//deletion_beginning();
	/*printf("Enter the data you want to insert in between the nodes: \n");
    scanf("%d",&data);
    printf("Enter the position at which you want to insert the nodes: \n");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("Enter a valid position: ");    
    }
    else 
    {
        ins_pos(data,pos);
    }*/
	// search();
	 display();
	 reverse();
	 display();
	//return 0;
}



 // printf("Enter the number of nodes: \n");
																		//scanf("%d",&n);
																		//printf("Enter the data for the nodes: \n");
																		//for(i=0;i<n;i++)
																		//{
																		 //   scanf("%d",&data);
																		   // ins(3);
																	   // }
