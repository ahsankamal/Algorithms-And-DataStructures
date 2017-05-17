#include<iostream>

using namespace std;

int main()
{
cout<<"Enter the size of array\n";
long n;
cin>>n;
cout<<"Enter "<<n<<" space seperated integers\n";
long *arr = new long[n];
for(long i=0;i<n;i++){
	cin>>arr[i];
}

sort(arr, arr+n);//in ascending order
	cout<<"Sorted array:\n";
	for(long i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

long sum;
cout<<"Enter the value of sum\n";
cin>>sum;

long left=0,right=n-1;
bool pair_exist = false;

while(left<right){
	long left_plus_right = arr[left] + arr[right];
	if(left_plus_right==sum)
		{
			cout<<"Pair:("<<arr[left]<<","<<arr[right]<<")\n";
			left++;//to find next pair whose sum is equal to given sum
			pair_exist = true;
		}	
	else if(left_plus_right<sum)//move left pointer
		left++;
	else//move right pointer
		right--;
}

if(pair_exist == false){
	cout<<"No pair exist with sum equal to "<<sum<<endl;
} 

	return 0;
}


/* 
Test case1:
Enter the size of array
8
Enter 8 space seperated integers
12 3 5 6 2 7 8 4 
Sorted array:
2 3 4 5 6 7 8 12 
Enter the value of sum
8
Pair:(2,6)
Pair:(3,5)


Test case 2:
Enter the size of array
10
Enter 10 space seperated integers
1 2 3 5 6 4 7 8 10 5
Sorted array:
1 2 3 4 5 5 6 7 8 10 
Enter the value of sum
9
Pair:(1,8)
Pair:(2,7)
Pair:(3,6)
Pair:(4,5)
*/