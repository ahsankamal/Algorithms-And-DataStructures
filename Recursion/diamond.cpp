#include<iostream>
using namespace std;

void diamond(int index, int odd_number);
int main()
{
	int odd_number;
	cin>>odd_number;
	diamond(1,odd_number);
	cout<<endl;
	return 0;

}
void diamond(int index, int odd_number)
{
	if(index>odd_number)
		return;

	for(int i=1;i<=(odd_number-index)/2;i++)
		cout<<" ";
	for(int i=1;i<=index;i++)
		cout<<"*";
	cout<<endl;

	diamond(index+2,odd_number);

	if(index!=odd_number)
	{
		for(int i=1;i<=(odd_number-index)/2;i++)
			cout<<" ";
		for(int i=1;i<=index;i++)
			cout<<"*";
		cout<<endl;
	}
	

}
/*

Test case 1:
5
  *
 ***
*****
 ***
  *

Test case 2:
11
     *
    ***
   *****
  *******
 *********
***********
 *********
  *******
   *****
    ***
     *

*/     