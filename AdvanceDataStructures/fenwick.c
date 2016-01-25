//fenwick tree or Binary Indexed tree implementation
#include<stdio.h>
int main()
{
long int sum,add,i,j,k,l,x,freq[10000],tree[10000],n,m;

printf("enter the size of tree i.e no of nodes in a tree\n");
scanf("%ld",&n);

printf("enter the freq of each node \n");
for(i=0;i<n;i++)
scanf("%ld",&freq[i]);

// building fenwick tree
for(i=1;i<=n;i++)
{
	add=freq[i-1];
	j=i;
		while(j<=n)
		{	
		tree[j]=tree[j]+add;
		j=j+(j&(-j));
		}
}

printf("fenwick tree initially\n");
for(i=1;i<=n;i++)
printf("%ld ",tree[i]);
printf("\n");

printf("enter the no of queries\n");
scanf("%ld",&m);
while(m--)
{	
scanf("%ld",&k);
switch(k)
{
case 1: //query of type 1 , eg to add value x to index l;
	scanf("%ld%ld",&l,&x);
	while(l<=n)
	{
	tree[l]=tree[l]+x;//we can add or subtract acc. to the question
	l=l+(l&(-l));
	} 
	printf("fenwick tree after query 2\n");
	for(i=1;i<=n;i++)
	printf("%ld ",tree[i]);
	printf("\n");
	break;
case 2: 
//query of type 2 , To find prefix sum of index l 
	scanf("%ld",&l);
	sum=0;
	while(l>0)
	{
	sum=sum+tree[l];
	l=l-(l&(-l));
	}
	printf("cumulative freq is %ld\n",sum);
	break;



}
}




return 0;
}
