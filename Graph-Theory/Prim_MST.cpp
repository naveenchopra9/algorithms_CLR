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

long long prim_MST(int s)
{
		for (int i = 0; i < MAX; ++i)
		{
			marked[i]=false;
		}
		/*
		pair object for graph is assumed to be (node, weight)
		This declares a priority_queue containing pair<long long, int> instances 
		where a vector< pair<long long, int>> is the underlying container of the 
		priority queue
		The greater<pair<long long, int>> is used as the Comparator function object for the queue, 
		checking whether the LHS pair is greater than the RHS pair
		*/

		priority_queue< P,vector<P>,greater<P> >Q;

		int x;

		long long minCost=0;
		
		P p;
		
		int z;
		
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

			minCost += p.first;

			marked[x]=true;

			for (int i = 0; i < adj[x].size(); ++i)
			{
					z=adj[x][i].second;
					if(marked[z]==false)
						Q.push(adj[x][i]);
			}

		}
		return minCost;
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
	cout<<"Minimum cost"<<prim_MST(1);
	return 0;
}
