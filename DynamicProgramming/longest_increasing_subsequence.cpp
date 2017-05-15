#include<iostream>
using namespace std;

long longest_increasing_subsequence(long *sequence, long n, long* LIS, long* aux);//returns index of last element of longest_increasing_subsequence

int main()
{
	long n;
	cout<<"Enter the length of sequence"<<endl;
	cin>>n;

	long *sequence = new long[n];
	long *LIS = new long[n];//LIS[i]: stores the length of longest increasing subsequence ending at i, such that sequence[i] is the last element.
	long *aux = new long[n];//auxiliary array to print longest increasing subsequence. aux[i] stores the index of previous element.

	cout<<"Enter "<<n<<" comma seperated integers representing the sequence"<<endl;
	for(long i=0; i<n; i++)
		{
			cin>>sequence[i];
			LIS[i]=1;
			aux[i]=-1;
		}	


	long last_index = longest_increasing_subsequence(sequence, n, LIS, aux);
	cout<<"Length of longest increasing subsequence is "<<LIS[last_index]<<endl;

	cout<<"Longest increasing subsequence in reverse order"<<endl;
	for(long i=last_index; i>=0; i=aux[i])
	{
		cout<<sequence[i]<<" ";
	}
	cout<<endl;

	return 0;
}



long longest_increasing_subsequence(long *sequence, long n, long *LIS, long *aux)
{
	long index_of_last_element_of_LIS = -1;
	long length_of_LIS = 1;

	for(long i=0; i<n; i++){

		for(long j=0; j<i; j++){
			if(sequence[i] > sequence[j] && LIS[i] < LIS[j] + 1){
				LIS[i] = LIS[j] + 1;
				aux[i] = j;

				if(LIS[i]>length_of_LIS)
				{
					length_of_LIS = LIS[i];
					index_of_last_element_of_LIS = i;
				}
			}
		}
	}
	return index_of_last_element_of_LIS;
}

/*
Test case 1:
Enter the length of sequence
12
Enter 12 comma seperated integers representing the sequence
132 213 23 42 9 67 12 45 25 13 90 80

Output:
Length of longest increasing subsequence is 4
Longest increasing subsequence in reverse order
90 67 42 23 
 

Test case 2:
Enter the length of sequence
10
Enter 10 comma seperated integers representing the sequence
12 23 29 23 30 45 32 34 90 43

Output:
Length of longest increasing subsequence is 7
Longest increasing subsequence in reverse order
90 34 32 30 29 23 12 

*/