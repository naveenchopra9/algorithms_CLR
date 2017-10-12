#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

const int MAX=100001;
typedef pair <long long ,int> P;
bool marked[MAX];
vector <P> adj[MAX];
const int INF=999999;
int d[MAX];
void Diskstra(int s)
{
		/*
			pair object for graph is assumed to be (node, weight)
			This declares a priority_queue containing pair<long long, int> instances 
			where a vector< pair<long long, int>> is the underlying container of the 
			priority queue
			The greater<pair<long long, int>> is used as the Comparator function object for the queue, 
			checking whether the LHS pair is greater than the RHS pair
		*/

		priority_queue< P,vector<P>,greater<P> >Q;
		memset(d,INF,sizeof(d));
		memset(marked,false,sizeof(marked));
		int x;
		/*
		pair object for graph is assumed to be (node, weight). d[] array
		holds the shortest path from the source. It contains INF if not
		reachable from the source.
		*/
		P p;
		d[s]=0;
		int y,z;
		/*
	    Reset the distance array and set INF as initial value. The
	    source node will have weight 0. We push (0, start) in the
	    priority queue as well that denotes start node has 0 weight.
	    */
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
		
}

int main()
{
	int vertice,edges;
	cout<<"Enter vertice and edges:";
	cin>>vertice>>edges;
	int x,y;
	long long weight;

	for(int i = 0; i < edges; ++i)
	{
			cin>>x>>y>>weight;
			adj[y].push_back(make_pair(weight,x));	
			adj[x].push_back(make_pair(weight,y));	
	}	
	Diskstra(0);
	for (int i = 0; i < vertice; ++i)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
