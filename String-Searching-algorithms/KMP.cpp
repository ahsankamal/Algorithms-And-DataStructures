//
#include<bits/stdc++.h>
using namespace std;
void calculateLPS(int *lps,int n,string str);
int main()
{
	string text,pattern;
	cin>>text;
	cin>>pattern;
	int n=pattern.length();
	int m=text.length();
	int *lps=(int *)malloc(sizeof(int)*n);
//preprocessing the pattern
	calculateLPS(lps,n,pattern);
	cout<<"LPS[] : ";
	for(int i=0;i<n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	//Adv of LPS[] is that we are not moving backward in text 
	//when a mismatch occurs while traversing it. Hence, runtime complexity is O(M)
int i=0,j=0;
while(j<m){

		if(pattern[i]==text[j])
		{
			i++;j++;
			if(i==n)
				{
					cout<<"Pattern exists at index "<<j-n<<endl;
				}
		}
		else
		{
			if(i!=0)
			i=lps[i-1];
			else
				j++;
		}
}
free(lps);

	return 0;
}
void calculateLPS(int *lps,int n,string str)
{
int i,j;
lps[0]=0;
i=0;j=1;
while(j<n){
	if(str[i]==str[j])
	{
		i++;lps[j]=i;j++;
	}
	else
	{
		if(i==0)
			{lps[j]=0;j++;}
		else
			i=lps[i-1];
	}

}
}
//lps[i] -stores length of longest common prefix which is also a suffix in pattern[0...i] 
/*For the pattern “AABAACAABAA”, lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
For the pattern “ABCDE”, lps[] is [0, 0, 0, 0, 0]
For the pattern “AAAAA”, lps[] is [0, 1, 2, 3, 4]
For the pattern “AAABAAA”, lps[] is [0, 1, 2, 0, 1, 2, 3]
For the pattern “AAACAAAAAC”, lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]
*/