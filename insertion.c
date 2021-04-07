#include "stdio.h"

int main()
{
	int arr[5]={54,21,34,6,44};
	int i,j,key;
	int n=5;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	printf("soreted array:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
		
		

