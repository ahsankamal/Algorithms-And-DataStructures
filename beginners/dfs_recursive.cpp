// A c++ program to demonstrate DFS traveral on undirected graph.
/*
TEST CASE

INPUT:
Enter the no of edges
7
1 2
1 3
1 5
2 4
2 6
3 7
5 6
Enter the starting node
2

OUTPUT:
2 1 3 7 5 6 4 
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int>nodes[1000];
bool visited[1000] = { false };
void dfs_recursive(int current){
	if(!visited[current]){
		cout<<current<<" ";
		visited[current] = true;
		for(vector<int>::iterator it=nodes[current].begin(); it!=nodes[current].end(); ++it)
			if(visited[*it]==false)
				dfs_recursive(*it);
	}
}

int main()
{
int edges,a,b;
cout<<"Enter the no of edges"<<endl;
	cin>>edges;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	cout<<endl;
	//Adj list representation 
for(int i=0;i<1000;i++)
{
	if(!nodes[i].empty())
	{	cout<<"[ "<<i<<" ]"<<"-->";
		for(vector<int>::iterator it=nodes[i].begin();
				it!=nodes[i].end();++it)
		{
		cout<<*it<<"-->";
		}
		cout<<"NULL"<<endl;
	}	
}

int start;
cout<<"\nEnter the starting node"<<endl;
cin>>start;
dfs_recursive(start);
cout<<endl;
return 0;
}
