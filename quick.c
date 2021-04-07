#include"stdio.h"

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=partition(arr,low,high);
		quicksort(arr,low,mid-1);
		quicksort(arr,mid+1,high);
	}
}

int main()
{
	int arr[5]={23,55,21,5,87};
	int n,i;
	n=sizeof(arr)/sizeof(int);
	printf("given array:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}

