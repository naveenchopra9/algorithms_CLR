
#include <iostream>
#include <list>
#include <bits/stdc++.h>
using namespace std;	
class graph
{
	int V;
	list<int>*adj; // adjacency lists
	void Utildfs(int v,bool visited[]);
public:
	graph(int V); //constructor
	void addedge(int  v ,int w);//function to edge in  graph
	void dfs(int s);//print bfs to traversal from given source
};
graph:: graph(int V)
{
	this->V=V;
	adj=new list<int>[V];	
}
void graph :: addedge(int v ,int w)
{
	adj[v].push_back(w);
}
void graph :: Utildfs(int s,bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";
	list<int>::iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
		{
			Utildfs(*it,visited);

		}
	}
}
void graph :: dfs(int s)
{
 	 bool *visited =new bool[V];
 	 for (int i = 0; i < V; ++i)
 	 {
 	 	visited[i]=false;
 	 }
 	 for (int i = 0; i < V; ++i)
 	 {
 	 	if(visited[i]==false)
 			 Utildfs(i,visited);
 	 }
}
int main()
{
	int n;
	cin>>n;
	graph g(n);
	int m,p,q,t;
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
	  cin>>p>>q;
	  g.addedge(p,q);
	}
     while(1)
     {
     	cin>>t;
     	g.dfs(t);
     }
	return 0;
}
