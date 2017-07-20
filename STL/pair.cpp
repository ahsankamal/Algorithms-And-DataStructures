#include<iostream>
#include<utility>
using namespace std;

int main()
{

	pair<string,int> p1,p2;
	cout << "Enter 2 space seperated strings\n";
	string str;
	cin>>str;
	p1 = make_pair(str,str.length());
	cin>>str;
	p2 = make_pair(str,str.length());
	cout<<"Pair 1: ("<<p1.first<<", "<<p1.second<<")"<<endl;
	cout<<"Pair 2: ("<<p2.first<<", "<<p2.second<<")"<<endl;

	swap(p1,p2);
	cout << "After swaping :\n";
	cout<<"Pair 1: ("<<p1.first<<", "<<p1.second<<")"<<endl;
	cout<<"Pair 2: ("<<p2.first<<", "<<p2.second<<")"<<endl;

	return 0;
}
/*
Enter 2 space seperated strings
werqw fdgdffsasdgfs
Pair 1: (werqw, 5)
Pair 2: (fdgdffsasdgfs, 13)
After swaping :
Pair 1: (fdgdffsasdgfs, 13)
Pair 2: (werqw, 5)

*/