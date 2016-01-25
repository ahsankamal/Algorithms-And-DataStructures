//Implementation of Suffix array O(n*logn*logn)
//Kasai's algorithm for computing Longest common prefix array in O(n)
//Solution of DISUBSTR - Distinct Substrings problem in Spoj
#include<bits/stdc++.h>
using namespace std;
long cmp(long i,long j);
string str;
long gap=1,sa[1000007],pos[1000007],tmp[1000007],n,lcp[1000007];
int main()
{
	int t;
	cout<<"Enter the no of Test cases\n";
	cin>>t;
	while(t--){


cin>>str;
n=str.length();
int i;
for(i=0;i<n;i++)
{
	sa[i]=i;
	pos[i]=str[i];
	tmp[i]=0;
	lcp[i]=0;
}
	for(gap=1;;gap=gap*2)
	{
				//printf("%ld ",gap);
		sort(sa,sa+n,cmp);
		for(i=0;i<n-1;i++)
			tmp[i+1]=tmp[i]+cmp(sa[i],sa[i+1]);
		for(i=0;i<n;i++)
			pos[sa[i]]=tmp[i];

		if(tmp[n-1]==n-1)//means all suffix are sorted
			break;
	}
	cout<<"Suffix Array :\n";
	for(i=0;i<n;i++)
		cout<<sa[i]<<" ";
	cout<<endl;

	long k=0,j;
	for(i=0;i<n;i++)
	{
		pos[sa[i]]=i;
	}
		for(i=0;i<n;i++)
		{
			if(pos[i]==n-1)
			{
				k=0;
				continue;
			}
			
			j=sa[pos[i]+1];
			while(i+k<n&&j+k<n&&str[i+k]==str[j+k])
				k++;
			
			lcp[pos[i]]=k;
			if(k>0)
				k--;
		}

	cout<<"Longest Common Prefix :\n";
	for(i=0;i<n;i++)
		cout<<lcp[i]<<" ";
	cout<<endl;	




//Counting no of distinct substrings
		k=0;
		for(i=0;i<n;i++){
				k=k+n-sa[i]-lcp[i];
			}
		printf("No of Distinct Substrings : %ld\n",k);
		cout<<endl;
}
return 0;
}
long cmp(long i,long j)
{
if(pos[i]!=pos[j])
	return pos[i]<pos[j];
i=i+gap;
j=j+gap;
if(i<n&&j<n)
	return pos[i]<pos[j];
else
	return i>j;

}
/*
Explanation for the testcase with string ABABA:
len=1 : A,B
len=2 : AB,BA
len=3 : ABA,BAB
len=4 : ABAB,BABA
len=5 : ABABA
Thus, total number of distinct substrings is 9.
*/
