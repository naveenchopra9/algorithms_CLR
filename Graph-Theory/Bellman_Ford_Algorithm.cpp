#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;
struct Edge
{
	int s,d,w;
};
struct graph
{
	int E;
	int V;
	struct Edge* edge;
};
//create graph of v to u
struct graph* creategraph(int v,int e)
{
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	graph->E=e;
	graph->V=v;
	graph->edge=(struct Edge*)malloc((graph->E)*sizeof(struct Edge));
	return graph;
}
void bfa(struct graph* graph ,int sr)
{
	int distance[graph->V];
	for (int i = 0; i < graph->V; ++i)
	{
		distance[i]=999999;
	}
	distance[sr]=0;

	for (int i = 1; i < graph->V; ++i)
	{
		for(int j =0 ; j< graph->E ; j++)
			{
				int u=graph->edge[j].s;
				int v=graph->edge[j].d;
				int weight=graph->edge[j].w;
				//cout<<u<<" "<<v<<" "<<weight<<endl;
					if(distance[u]!=999999&&distance[u]+weight<distance[v])
						distance[v]=distance[u]+weight;
			}
	}
	//to check negative cycles
		for (int i = 0; i < graph->E; ++i)
			{
				int u=graph->edge[i].s;
				int v=graph->edge[i].d;
				int weight=graph->edge[i].w;
					if(distance[u]!=999999&&distance[u]+weight<distance[v])
						cout<<"Graph contains negative cycles"<<endl;
			}
		cout<<"Distance from source:"<<endl;
		cout<<"Source"<<"   "<<"weight"<<endl;
		for (int i = 0; i <graph->V; ++i)
			{
			   cout<<i<<"          "<<distance[i]<<" "<<endl;
			}

	return;
}
int main()
{
 int ne;
 int nv;
 cout<<"Enter number of vertices:";
 cin>>nv;
 cout<<"Enter number of edges:";
 cin>>ne;
 struct graph* graph=creategraph(nv,ne);
 cout<<"Enter v and u,and weight:"<<endl;
 int nv1,nv2,w;
 for (int i = 0; i <ne ; ++i)
 {
 	cin>>nv1>>nv2>>w;
 	graph->edge[i].s=nv1;
 	graph->edge[i].d=nv2;
 	graph->edge[i].w=w;
 }
   bfa(graph,0);
}