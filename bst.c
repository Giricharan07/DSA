#include<stdio.h>
#include<stdlib.h>



struct bstree
{
	int info;
	struct bstree *lchild;
	struct bstree * rchild;
};

struct bstree *createBST(struct bstree *root, int ele)
{
	if(root == NULL)
	{
		root =(struct bstree *)malloc(sizeof(struct bstree));
		root->info = ele;
		root->lchild = root->rchild = NULL;
	}
	else if(root->info == ele)
		printf("Node already exists");
	else if(root->info > ele)
		root->lchild = createBST(root->lchild, ele);	
	else if(root->info < ele)
		root->rchild = createBST(root->rchild, ele);	
	return root;
}

void InOrder(struct bstree *root)
{
	if(root)
	{
		InOrder(root -> lchild);
		printf("%d \n",root->info);
		InOrder(root -> rchild);
	}
}

struct bstree * findMin(struct bstree *root)
{
	if(root == NULL)
		return root;
	else if(root->lchild == NULL)
		return root;
	else
		return findMin(root->lchild); 
}

struct bstree *deleteNode(struct bstree *root, int ele)
{
	struct bstree *temp;
	if(root == NULL)
		printf("element not found");
	else if(ele < root->info)
		root->lchild = deleteNode(root->lchild,ele);
	else if(ele > root->info)
		root->rchild = deleteNode(root->rchild,ele);
	else if(root->lchild && root->rchild)
	{
		temp = findMin(root->rchild);
		root->info = temp->info;
		root->rchild = deleteNode(root->rchild, root->info);
	}
	else
	{
		temp = root;
		
		if(root->lchild == NULL)
			root = root->rchild;
		else if(root->rchild == NULL)
			root = root->lchild;
		
		free(temp);
	}
	return root;
}





void main()
{
  struct bstree *root = NULL;
  root = createBST(root,6);
  root = createBST(root,4);
  root = createBST(root,2);

  InOrder(root);

  root = deleteNode(root,4);
  InOrder(root);


}