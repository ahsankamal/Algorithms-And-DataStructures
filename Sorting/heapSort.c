#include<stdio.h>
#include<stdlib.h>
void heapify(int *,int ,int );
void buildMinHeap(int *,int);
void heapSort(int *,int );
int main()
{
	int i,j,n,*heap;
	scanf("%d",&n);
	heap=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",heap+i);
	buildMinHeap(heap,n);
	for(i=0;i<n;i++)
		printf("%d ",heap[i]);
	printf("\n");
	heapSort(heap,n);
	for(i=0;i<n;i++)
		printf("%d ",heap[i]);
return 0;
}
void buildMinHeap(int *h,int n)
{	//building heap structure 	
	//shiftdown O(n)
	//more efficient 
	//lesser no of swapping required
	int i;
	for(i=n-1;i>=0;i--)
		heapify(h,i,n);
}
void heapify(int *heap,int ind,int n)
{
	int tmp,k;
	while(ind<n)
	{
		if(ind*2+1>=n)
			break;
		else if(ind*2+2>=n)
			k=ind*2+1;
		else
		{
		//min among the children
		if(heap[ind*2+1]>heap[ind*2+2])
			k=ind*2+2;
		else
			k=ind*2+1;
		}
		
		if(heap[ind]>heap[k])
		{
			tmp=heap[ind];
			heap[ind]=heap[k];
			heap[k]=tmp;
			ind=k;
		}
		else
			break;
	}
}
void heapSort(int *heap,int n )
{
	int i,j;
	i=n-1;
	while(i>=0)
	{
		//swap 0th with ith element
		j=heap[0];
		heap[0]=heap[i];
		heap[i]=j;
		i--;//shrinking unsorted area
		heapify(heap,0,i);
	}

}
