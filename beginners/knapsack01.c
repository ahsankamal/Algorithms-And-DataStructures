#include<stdio.h>
//#define max a > b ? a : b
//#define long int li
long int max(long int a,long int b)
{
if(a>b)
return a;
else
return b;
} 

int main()
{
  long int includeditem[1000]={0},j,knapsack,i,wt,n,itm;
  long int dp[1000][1000],weight[1000],value[1000];
  printf("enter the no.of items\n");
	scanf("%ld",&n);
printf("enter the size of knapsack\n");
scanf("%ld",&knapsack);
printf("enter the weight of each item along with its value\n");
printf("     weight || item\n");
for(i=1;i<=n;i++)
{
printf("item%ld ->  ",i);
scanf("%ld%ld",&weight[i],&value[i]);
}
for(itm=0;itm<=n;itm++)
   {	
	for(wt=0;wt<=knapsack;wt++)
	{                     /*if size of knapsack is 0 or there is 			no item ,then no itm can be put inside knapsack*/
	if(itm==0||wt==0)
		{dp[itm][wt]=0;continue;}
	 if(wt<weight[itm])//can't put item
   	dp[itm][wt]=dp[itm-1][wt];
	/*can put but need to see which will generate more profit 		either its inclusion or not(if assumed knapsack i.e wt 		>=weight of item)*/
	else 
	dp[itm][wt]=max(dp[itm-1][wt],value[itm]+dp[itm-1][wt-weight[itm]]);
	//printf("itm=%ldwt=%ld %ld\t",itm,wt,dp[itm][wt]);}
	}
   }


printf("optimal solution is %ld\n",dp[n][knapsack]);
i=n;
j=knapsack;
//for(itm=n;itm>=0;itm--)  
while(i>0&&j>0)
{ if(dp[i][j]!=dp[i-1][j])
   { includeditem[i]=1;
	j=j-weight[i];
   }
i--;
}
for(i=1;i<=n;i++)
printf(" %ld ",includeditem[i]);
return 0;
}





