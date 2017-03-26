#include<iostream>
using namespace std;

long cut_rod(long *price, long n, long* saved, long* cuts);
void print_cut_rod_solution(long *cuts, long n);

int main()
{
	long n;
	cout<<"Enter the length of rod"<<endl;
	cin>>n;

	long *cuts = new long[n+1];
	long *saved = new long[n+1];//auxiliary array to save solution of subproblem
	for(long i=0;i<=n;i++)
		saved[i]=-1;

	long *price = new long[n+1];
	cout<<"Enter "<<n<<" comma seperated integers representing prices of pieces"<<endl;
	for(long i=1;i<=n;i++)
		cin>>price[i];//price of the rod of size i


	//Assuming each cut is free.
	long max_revenue = cut_rod(price, n, saved, cuts);
	cout<<"Maximum obtainable revenue is "<<max_revenue<<endl;
	cout<<"Cut Rod Solution"<<endl;
	print_cut_rod_solution(cuts,n);

	return 0;
}



long cut_rod(long *price, long n, long *saved, long *cuts)
{
	if(saved[n]>=0)//memoization
		return saved[n];
	else if(n==0)
		 return 0;
	else
	{	
		long max_revenue = INT_MIN;
		long cut=n;	
		for(long i=1;i<=n;i++)
		{
			// max_revenue = max(max_revenue, price[i] + cut_rod(price, n-i, saved));
			long revenue = price[i] + cut_rod(price, n-i, saved, cuts);
			if(max_revenue < revenue)
			{
				max_revenue = revenue;
				cut = i;
			}
		}	
		saved[n] = max_revenue;
		cuts[n] = cut;
		return max_revenue;
	}	
}

void print_cut_rod_solution(long *cuts, long n){

	while(n>0)
	{
		cout<<cuts[n]<<", ";
		n-=cuts[n];
	}
	cout<<endl;
}
/*

Test Case1:

Input:
Enter the length of rod
10
Enter 10 comma seperated integers representing prices of pieces
1 5 8 9 10 17 17 20 24 21

Output:
Maximum obtainable revenue is 27
Cut Rod Solution
2, 2, 6, 



*/