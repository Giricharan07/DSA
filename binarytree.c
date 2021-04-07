#include<stdio.h>
#include<stdlib.h>
struct btree* createBT();
void InOrder(struct btree *root);
struct btree
{
	int info;
	struct btree *lchild;
	struct btree * rchild;
};
 int main()
{
	struct btree *root;
	root = NULL;
	root = createBT();
    InOrder(root);
}
struct btree * createBT()
{
	struct btree *newNode;
	newNode = NULL;
	int data;

	printf("Enter the data : ");
	scanf("%d", &data);

	if(data != 999)
	{
		newNode = (struct btree *)malloc(sizeof(struct btree));
		newNode ->info = data;

		printf("Enter the left child of %d : ",data) ;
		newNode ->lchild = createBT();

		printf("Enter the right child of %d : ",data) ;
		newNode ->rchild = createBT();
	}
	return newNode;

}

    void InOrder(struct btree *root)
{
	if(root!=NULL)
	{
		InOrder(root -> lchild);
		printf("%d",root->info);
		InOrder(root -> rchild);
	}
}

