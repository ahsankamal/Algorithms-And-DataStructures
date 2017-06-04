#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[], int low, int high, int val){
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==val)
			return mid;
		else if(arr[mid]>val)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int main()
{
	cout<<"Enter the size of array\n";
	int n,arr[1000];
	cin>>n;
	cout<<"Enter "<<n<<" space seperated integers\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int value;
	cout<<"Enter the value you wanna search\n";
	cin>>value;
	sort(arr,arr+n);
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	int index = binary_search(arr,0,n,value);
	if(index==-1)
		cout<<value<<" not found.\n";
	else
		cout<<value<<" found at "<<index<<" index."<<endl;
	return 0;
}

/*
Test case:

Enter the size of array
10
Enter 10 space seperated integers
33 5 77 -1 -44 66 88 4 7 66
Enter the value you wanna search
77
Sorted array: -44 -1 4 5 7 33 66 66 77 88 
77 found at 8 index.
*/