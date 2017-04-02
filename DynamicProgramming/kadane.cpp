#include<iostream>
#include<climits>
using namespace std;

int main()
{
cout<<"Enter array size\n";
int n;
cin>>n;
cout<<"Enter "<<n<<" space seperated integers\n";
int* array = new int[n];
for(int i=0;i<n;i++)
	cin>>array[i];

//largest subarray sum
int largest_subarray_sum_so_far = INT_MIN;
int subarray_sum_ending_here = 0;
int start = 0, end = 0, new_start = 0;

//kadane's algo
for(int i=0;i<n;i++){
	subarray_sum_ending_here+=array[i];
	if(largest_subarray_sum_so_far<subarray_sum_ending_here){
		largest_subarray_sum_so_far = subarray_sum_ending_here;
		start = new_start;
		end = i;
	}
	if(subarray_sum_ending_here < 0){//start new subarray from i+1
		subarray_sum_ending_here = 0;
		new_start = i+1;
	}
}

cout<<"Largest subarray sum: "<<largest_subarray_sum_so_far<<endl;
cout<<"Subarray: ";
for(int i=start; i<=end; i++){
	cout<<array[i]<<" ";
}
cout<<endl;


	return 0;
}

/*

Test case 1:

Input:
Enter array size
10
Enter 10 space seperated integers
-3 5 -2 -1 3 -2 4 1 -5 3

Output:
Largest subarray sum: 8
Subarray: 5 -2 -1 3 -2 4 1 




Test case 2:

Input:
Enter array size
8
Enter 8 space seperated integers
-5 -33 -53 -2 -11 -3 -4 -6

Output:
Largest subarray sum: -2
Subarray: -2 
*/