#include<bits/stdc++.h>
using namespace std;

bool sort_by(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second < b.second;//sorting vector in ascending order by second element of pair
}

int main()
{
vector<pair<int,int> > vec;
int n;
cout<<"Enter total number of elements\n";
cin>>n;
cout<<"Enter 2 space seperated integers in each next "<<n<<" lines\n";

int x,y;
for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		vec.push_back(make_pair(x,y));
	}
//sort(vec.begin(), vec.end()); by default sort function will sort the vector by first element of pair
sort(vec.begin(), vec.end(), sort_by);

	cout<<"After sorting vector by second element of pair: \n";
	for(vector<pair<int,int> >::iterator it = vec.begin(); it!=vec.end(); it++ )
		cout<<it->first<<" "<<it->second<<endl;

	return 0;
}
/*
Test case 1:
Enter total number of elements
3
Enter 2 space seperated integers in each next 3 lines
21 23
3 6
5 3
After sorting vector by second element of pair: 
5 3
3 6
21 23


Test case 2:
7
Enter 2 space seperated integers in each next 7 lines
21 34 
21 42
12 3
12 2
31 464
12 32
1231 31
After sorting vector by second element of pair: 
12 2
12 3
1231 31
12 32
21 34
21 42
31 464
*/