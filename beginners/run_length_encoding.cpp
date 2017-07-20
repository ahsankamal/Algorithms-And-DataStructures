#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	int t;
	cout<<"Enter the no of test cases\n";
	cin>>t;
	while(t--){
		string str,rle="";
		stringstream out;
		cout<<"Enter a string\n";
		cin>>str;

		int len = str.length();
		int start = 0;
		for(int i=1;i<len;i++){
			if(str[start]!=str[i]){//start of new char sequence
				out<<i-start;
				string count = out.str();//converting int to string
				// rle = rle + to_string(start); //in C++ 11
				rle = rle + str[start] + count;
				out.str("");//flushing stringstream
				start = i;
			}
		}
		out<<len-start;//last char count
		string count = out.str();
		rle = rle + str[start] + count;

		cout<<"Run length encoding: "<<rle<<endl;
	}
	return 0;
}
/*
test cases:
3

Enter a string
aaaaaaaabbbbqqwooop
Run length encoding: a8b4q2w1o3p1

Enter a string
abc
Run length encoding: a1b1c1

Enter a string
qprqqqpp
Run length encoding: q1p1r1q3p2


*/