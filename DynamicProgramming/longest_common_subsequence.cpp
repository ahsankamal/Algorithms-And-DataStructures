#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

int longest_common_subseq(string s1, string s2, int m, int n, int **lcs);

int main()
{

string s1,s2;
cout<<"Enter first sequence\n";
cin>>s1;
cout<<"Enter second sequence\n";
cin>>s2;


int len_s1 = s1.length();
int len_s2 = s2.length();

//dynamically allocating 2-d array (in heap)
int **lcs = new int*[len_s1+1];
for(int i = 0; i <= len_s1; i++)
	lcs[i] = new int[len_s2+1];

for(int i=0;i<=len_s1;i++)
	for(int j=0;j<=len_s2;j++)
		lcs[i][j]=0;

//lcs[i][j] = length of longest common subseq between s1[0...i] and s2[0...j]
cout<<"Length of longest common subsequence: "<<longest_common_subseq(s1, s2, len_s1, len_s2, lcs)<<endl;;
//lcs[len_s1][len_s2]: Length of longest common subsequence.

// for(int i=0;i<=len_s1;i++)
// {
// 	for(int j=0;j<=len_s2;j++)
// 		cout<<setw(5)<<lcs[i][j];
// 	cout<<endl;
// }
vector<char> long_common_subseq;
//lcs[len_s1][len_s2] table
while(len_s1>0 && len_s2>0){
	// cout<<s1[len_s1-1]<<" "<<s2[len_s1-1]<<endl;
	if(s1[len_s1 - 1] == s2[len_s2 - 1])
		{
			long_common_subseq.push_back(s1[len_s1 - 1]);
			len_s1--;
			len_s2--;
		}	
	else if(lcs[len_s1-1][len_s2]>lcs[len_s1][len_s2-1])//move in the direction of larger lcs[i][j]
		len_s1--;
	else
		len_s2--;
}

	
cout<<"Longest common subsequence: ";
for(int i=long_common_subseq.size()-1;i>=0;i--)
	cout<<long_common_subseq[i];
cout<<endl;


//cleaning up, to avoid memory leaks
for(int i = 0; i <= len_s1; ++i) {
    delete [] lcs[i];
}
delete [] lcs;

return 0;
}

//top-down, memoization
//Time complexity: O(m*n)
int longest_common_subseq(string s1, string s2, int m, int n, int **lcs){

	if(m==0 || n==0)
		lcs[m][n]=0;
	else if(lcs[m][n]!=0)
		return lcs[m][n];
	else if(s1[m-1]==s2[n-1])
		lcs[m][n] = 1 + longest_common_subseq(s1,s2,m-1,n-1,lcs);
	else
		lcs[m][n] = max(longest_common_subseq(s1,s2,m-1,n,lcs), longest_common_subseq(s1,s2,m,n-1,lcs));

return lcs[m][n];
}

/*
Test case:

Input:


Enter first sequence
ACCGGTCGAGTGCGCGGAAGCCGGCCGAA
Enter second sequence
GTCGTTCGGAATGCCGTTGCTCTGTAAA


Output:
Length of longest common subsequence: 20
Longest common subsequence: GTCGTCGGAAGCCGGCCGAA
*/
