 /*
	finds shortest paths between all pairs in O(V2 lg V + V E) time;
	Johnson's algorithm uses as subroutines both Dijkstra's algorithm and the Bellman-Ford algorithm
 */
	#include <iostream>
	#include <bits/stdc++.h>
	#include <vector>
	#include <utility>
	#include <queue>
	#include <functional>
	#include <algorithm>

	using namespace std;
	int vertice,edges;
	const int MAX=999999;
	 typedef pair <long long ,int> P;
	vector <P> adj[MAX];
	int dist[MAX];
	bool marked[MAX];
	int Bellman_Ford(int s)
	{

		for (int i = 0; i <=vertice ; ++i)
		{
			dist[i]=MAX;
			marked[i]=false;
		}
		dist[s]=0;
		int x,y;
		long long w;
		for (int k = 0; k <vertice; ++k)
		{
			for(int j =0 ; j<=vertice ; j++)
			{
				for (int i = 0; i < adj[j].size(); ++i)
				{
					x=adj[j][i].second;
					w=adj[j][i].first;
					if(dist[j]+w<dist[x]&&dist[j]!=999999)
					{
						dist[x]=w+dist[j];
					}
				}
			}	
		}
		int temp=0;
		for(int j =0 ; j<=vertice ; j++)
			{
				for (int i = 0; i < adj[j].size(); ++i)
				{
					x=adj[j][i].second;
					w=adj[j][i].first;
					if(dist[j]+w<dist[x]&&dist[j]!=999999)
					{
						temp=1;
					}
				}
			}
		// for (int i = 0; i <= vertice; ++i)
		// {
		// 	cout<<dist[i]<<" ";
		// }
		return temp;

	}
	int arr[10000][10000];
	void Dijkstra(int s,int l)
	{
		//int allvalue[MAX][MAX];
		int d[vertice];
		priority_queue< P,vector<P>,greater<P> >Q;
		memset(d,MAX,sizeof(d));
		memset(marked,false,sizeof(marked));
		int x;
		P p;
		d[s]=0;	
		int y,z;

		Q.push(make_pair(0,s));
		
		while(!Q.empty())
		{
		//select which have minimum weight 
			p=Q.top();
			Q.pop();
			x=p.second;
			//checkcycle in graph
			if(marked[x]==true)
				continue;
			 marked[x]=true;
			for (int i = 0; i < adj[x].size(); ++i)
			{
					z=adj[x][i].second;
					y=adj[x][i].first;
					if(d[z]>d[x]+y)// check if the next vertex distance could be minimized
					{
						d[z]=d[x]+y;
						Q.push(make_pair(d[z],z));
						}

		}
		}
		for (int i = 0; i < vertice; ++i)
		{
			//printf("%d  ",d[i] );
			arr[l][i]=d[i];	
		}
		printf("\n");
		

	}
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		//number of vertex and edges in graph
		cin>>vertice>>edges;

		int x,y;
		//weight of edge
		long long weight;
		int start=1;
		//input edge vertex and weight of edge
		for(int i = 0; i < edges; ++i)
		{
				cin>>x>>y>>weight;
				adj[x-1].push_back(make_pair(weight,y-1));		
		}	
		//add one zero weight edge in graph and connect to all other nodes in the graph
		for (int i = 0; i < edges; ++i)
		{
			adj[vertice].push_back(make_pair(0,i));
		}
		//print list of graph
		printf("\nadj G list \n\n");
		for (int i = 0; i <= vertice; ++i)
		{
			for(int j =0 ; j <adj[i].size() ; j++)
				cout<<"("<<adj[i][j].second<<" "<<adj[i][j].first<<")   ";
			cout<<endl;
		}
		//call bellman and find the distande to the added node in graph
		if(Bellman_Ford(vertice))//if have negative weight cycle in graph just return negative cycle 
			printf("Negative Cycle\n");
		else
		{
			int x;
			long long w;
			//chage the weight of weight of eged using formula adj[j][i].first=w+(dist[j] - dist[x]);
			for(int j =0 ; j<=vertice ; j++)
			{
				for (int i = 0; i < adj[j].size(); ++i)
				{
					x=adj[j][i].second;
					w=adj[j][i].first;
					adj[j][i].first=w+(dist[j] - dist[x]);
				}
			}
		}

		adj[vertice].clear();
		//call dijkstra for every vertex in graph 
		 for (int i = 0; i < vertice; ++i)
		{
			Dijkstra(i,i);
		}
		printf("final chage adj list of graph\n");
		for (int i = 0; i <= vertice; ++i)
		{
			for(int j =0 ; j <adj[i].size() ; j++)
				cout<<"("<<adj[i][j].second<<" "<<adj[i][j].first<<")   ";
			cout<<endl;
		}
		printf("\nmatrix of distance form every node:\n");
		for (int i = 0; i < vertice; ++i)
		{
			for(int j = 0 ; j< vertice ; j++)
			{
				printf("%d ",arr[i][j] );
			}
			printf("\n");
		}
		return 0;
	}
