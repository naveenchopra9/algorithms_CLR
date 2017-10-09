#include <iostream>
#include <list>
#include <bits/stdc++.h>
using namespace std;	
class graph
{
	int V;
	list<int>*adj; // adjacency lists
public:
	graph(int V); //constructor
	void addedge(int  v ,int w);//function to edge in  graph
	void bfs(int s);//print bfs to traversal from given source
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
void graph :: bfs(int s)
{
 	 bool *visited =new bool[V];
 	 for (int i = 0; i < V; ++i)
 	 {
 	 	visited[i]=false;
 	 }
 	 list <int>queue;
 	 visited[s]=true;
 	 queue.push_back(s);
 	 list<int>::iterator q;
 	 while(!queue.empty())
 	 {
 	 	s=queue.front();
 	 	cout<<s<<" ";
 	 	queue.pop_front();
 	 	for ( q = adj[s].begin(); q!=adj[s].end(); ++q)
 	 	{
 	 		if(!visited[*q])
 	 		{
 	 			visited[*q]=true;
 	 			queue.push_back(*q);
 	 		}
 	 	}
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
     	g.bfs(t);
     }
	return 0;
}
