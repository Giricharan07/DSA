// C program to demonstrate 
// delete operation in binary
// search tree
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};


struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}


struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key)
{
	
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	
	else {
		
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		
		struct node* temp = minValueNode(root->right);

		root->key = temp->key;
		
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// C function to search a given key in a given BST 
struct node* search(struct node* root, int key) 
{ 
	// Base Cases: root is null or key is present at root 
	if (root == NULL || root->key == key) 
	return root; 
	
	// Key is greater than root's key 
	if (root->key < key) 
	return search(root->right, key); 

	// Key is smaller than root's key 
	return search(root->left, key); 
}


// Driver Code
int main()
{
	
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 70);
	root = insert(root, 35);
	root = insert(root, 45);
	root = insert(root, 36);
	root = insert(root, 40);
	root = insert(root, 75);
	root = insert(root, 80);
	root = insert(root, 28);
	root = insert(root, 65);
	root = insert(root, 20);
	inorder(root);
	root = search(root,80);

	printf("Inorder traversal of the given tree \n");
	//inorder(root);
	preorder(root);

	//printf("\nDelete 20\n");
	//root = deleteNode(root, 20);
//	printf("Inorder traversal of the modified tree \n");
	//inorder(root);
/*
	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);*/

	return 0;
}

