//segment tree implementation
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long  build_segtree(long arr[],long segtree[],long left,long right ,long current_node);
long query(long segtree[],long left,long right,long l,long r,long current_node);
void update(long *segtree,long left,long right,long index,long diff,long current_node);
int main()
{
long newvalue,index,choice,sum,diff,i,j,l,r,m,n,arr[100001],segtree[300001];
scanf("%ld%ld",&n,&m);
for(i=0;i<n;i++)
scanf("%ld",&arr[i]);
i=build_segtree(arr,segtree,0,n-1,0);
for(i=0;i<3*n;i++)
printf("%ld ",segtree[i]);
printf("\n");
while(m--)
{
scanf("%ld",&choice);
if(choice==2)
{
scanf("%ld%ld",&l,&r);
l--;r--;//to make it appear as 1 based indexing
sum=query(segtree,0,n-1,l,r,0);
printf("%ld\n",sum);
}
else if(choice==1)
{
scanf("%ld%ld",&index,&newvalue);
index--;
diff=newvalue-arr[index];
arr[index]=newvalue;
//printf("%ld %ld %ld\n",diff,index,newvalue);
update(segtree,0,n-1,index,diff,0);
for(i=0;i<3*n;i++)
printf("%ld ",segtree[i]);
printf("\n");


}

}
return 0;
}
// A recursive function that constructs Segment Tree for array[left..right].
// current_node is index of current node in segment tree segtree[]
long  build_segtree(long arr[],long segtree[],long left,long right ,long current_node)
{
//printf("%ld %ld\n",current_node,segtree[current_node]); 
long mid;
if(left==right)
{// If there is one element in array, store it in current node of
    // segment tree and return
segtree[current_node]=arr[left];
return segtree[current_node];
}
mid=(left+right)/2;
// If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
segtree[current_node]=build_segtree(arr,segtree,left,mid,current_node*2+1)+build_segtree(arr,segtree,mid+1,right,current_node*2+2);

return segtree[current_node];
}

long query(long segtree[],long left,long right,long l,long r,long current_node)
{
long mid;
  // If segment of this node is a part of given range, then return the
    // sum of the segment
if(l<=left&&right<=r)
return segtree[current_node];
 
    // If segment of this node is outside the given range
if(l>right||r<left)
return 0;
 
    // If a part of this segment overlaps with the given range
mid=(left+right)/2;
return query(segtree,left,mid,l,r,2*current_node+1)+
query(segtree,mid+1,right,l,r,2*current_node+2);

}

void update(long *segtree,long left,long right,long index,long diff,long current_node)
{
long mid;    // Base Case: If the input index lies outside the range of this 
//printf("%ld %ld %ld\n",left,right,current_node);
if(index>right||index<left)
return;


    // If the input index is in range of this node, then update the value
    // of the node and its children

segtree[current_node]=segtree[current_node]+diff;


if(left!=right)
{
mid=(left+right)/2;
update(segtree,left,mid,index,diff,2*current_node+1);
update(segtree,mid+1,right,index,diff,2*current_node+2);

}
}






