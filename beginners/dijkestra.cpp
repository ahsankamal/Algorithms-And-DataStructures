#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long> > adjmat[300007];
long wt[300007],u,par[300007];
bool vis[300007];
long long dist[3000007],inf=1000000000000000000;
priority_queue< pair<long long,long>,vector< pair<long long,long> >,greater< pair<long long,long> > >pq;
int main()
{
long i,j,k,l,m,n;
scanf("%ld%ld",&n,&m);
for(i=1;i<=m;i++)
{
scanf("%ld%ld%ld",&j,&k,&wt[i]);
adjmat[j].push_back(pair<long long,int>(k,i));
adjmat[k].push_back(pair<long long ,int>(j,i));
}
scanf("%ld",&u);


for(i=1;i<=n;i++)
{
vis[i]=false;
dist[i]=inf;
}
pq.push(make_pair(0,u));
dist[u]=0;
while(!pq.empty())
{
long g,a,b;
g = pq.top().second;
pq.pop();
if(vis[g]==true)
{
continue;
}
vis[g]=true;
	for(i=0;i<adjmat[g].size();i++)
	{
	a=adjmat[g][i].first;b=adjmat[g][i].second;
	if(dist[a]>dist[g]+wt[b])
	{
	dist[a]=dist[g]+wt[b];
	pq.push(make_pair(dist[a],a));
	par[a]=b;//edge no b is included
	}
	else if(dist[a]==dist[g]+wt[b]&&wt[par[a]]>wt[b])
	{//new egde has even lesser wt so , reject older one n add new edge no.
	par[a]=b;
	}
	}
}
//printf("%ld\n",par[u]);
par[u]=0;
long long sum= 0;
for(i=1;i<=n;i++)
sum+=wt[par[i]];
cout<<sum<<endl;
//printf("%lld\n",sum);
//included edges are
for(i=1;i<=n;i++)
{
if(i!=u)
printf("%ld ",par[i]);
}
printf("\n");
return 0;
}
