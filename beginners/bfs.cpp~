// A c++ program to demonstrate BFS traveral on undirected graph
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
int edges,a,b;
vector<int>nodes[1000];
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

queue<int> que;
//initially que is empty
bool visited[1000];
// mark all the vertices as not visited
for(int i=0;i<1000;i++)
visited[i]=false;

int start;
cout<<"\nEnter the starting node"<<endl;
cin>>start;

//insert the starting node into the queue
que.push(start);
//mark the starting node as visited
visited[start]=true;


	cout<<"\nBFS Traversal\n";

while(!que.empty())
{
		//Dequeue a vertex from que and print it
		int front = que.front();
		cout<<front<<" ";
		que.pop();
// get all adjacent vertices of the dequeued vertex s
     // If an adjacent vertex has not been visited, 
       //then mark it as visited
        // and enqueue it
	for(vector<int>::iterator it=nodes[front].begin();
		it!=nodes[front].end();++it)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				que.push(*it);
			}
		}
}

	cout<<endl;
	return 0;
}
