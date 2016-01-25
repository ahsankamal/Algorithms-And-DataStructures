//This program is for storing all prime nos. from 1 to the given no.M(max range of M: 10000000) using sieve of eratosthetenes.
#include<stdio.h>
long  prime[1000000];
int sieve[10000000];
int main()
{
long int n,i,j,k;
printf("Enter the value of N\n");
scanf("%ld",&n);
//initially we assume all nos are prime.If sieve[i]=1 then i=prime;
for(i=2;i<n;i++)
sieve[i]=1;
//The assumption we take when generating primes till only sqrt of a number is that if for a number n there is a factor which is greater than sqrt(n) then there has to be a factor which is less than n

//eg factors of 100 are,1st group below sqrt(100)-> 2 ,4 ,5 ,10,
//			2nd group above sqrt(100)->20 25 50 100
//but observe 20=5*4,25=5*5,50=5*10,100=10*10//so 2nd group no. have factors in the first group therefore they will be sieved off while enumerating 1st group nos. 
// so for checking the primility of a no 10^14 storing prime nos till 10^7 will suffice
for(i=2;i*i<=10000000;i++)
{	if(sieve[i]==1)
	 for(j=i*i;j<=n;j=j+i)
		sieve[j]=0;
	
}
//now store prime nos in prime[]
//observe that no 2 prime nos are consecutive except 2,3 
j=0;
prime[j]=2;j++;
for(i=3;i<=n;i=i+2)
	{	if(sieve[i]==1)
		{prime[j]=i;j++;}
	}
printf("Total no of primes below %ld are-> %ld\nLast prime no is->%ld\n",n,j-1,
prime[j-1]);
for(i=0;i<j;i++)
printf("%ld ",prime[i]);
printf("\n");

return 0;
}
