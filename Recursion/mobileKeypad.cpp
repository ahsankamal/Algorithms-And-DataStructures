//Print all possible words from phone digits
//	            / 1 /   / 2 /   / 3 /
//		   /   /   /abc/   /def/

//	            / 4 /   / 5 /   / 6 /
//		   /ghi/   /jkl/   /mno/

//	           / 7  /   / 8 /   / 9  /
//		  /pqrs/   /tuv/   /wxyz/

//	          / * /   / 0 /   / # /
//		 /   /   /   /   /   /

#include<iostream>
#include<cstdio>
using namespace std;
int tmp[1000],total_strings=0;
int str[10][5]={
{0},
{0},
{3,'a','b','c'},
{3,'d','e','f'},
{3,'g','h','i'},
{3,'j','k','l'},
{3,'m','n','o'},
{4,'p','q','r','s'},
{3,'t','u','v'},
{4,'w','x','y','z'}
};
void recurAndPrint(string number,int n,int i){
	if(number[i]=='0'||number[i]=='1')
		{	//0 and 1 will not generate any char
			recurAndPrint(number,n,i+1);
			return ;
		}	
	if(i==n)
	{	//base case
		total_strings++;
		for(int x=0;x<n;x++)
			cout<<(char)tmp[x];
		cout<<endl;
	}
	int k=str[number[i]-'0'][0];	
	for(int j=1;j<=k;j++){
		tmp[i]=str[number[i]-'0'][j];
		recurAndPrint(number,n,i+1);
	}
}
int main()
{
string  number;
cin>>number;
int len=number.length();
recurAndPrint(number,len,0);
	cout<<endl;
	cout<<"Total no of strings = "<<total_strings<<endl; 
	return 0;
}
