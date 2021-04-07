#include"stdio.h"

int main()
{
	int i,j,arr[20],n;
	printf("enter the number of elements to sort:\n");
	scanf("%d",&n);
	printf("Enter the elements to sort\n:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted List\n:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
