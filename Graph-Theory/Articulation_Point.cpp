//Two condition most be hold for articulation point in graph
//  root vertex with two independent children in graph
// visited timevalue <=low timevalue of adj vertex	
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define IN ({int n; scanf("%d", &n);	n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
#define f first
#define s second
#define pb push_back	
#define p push
#define sz size()
const int INF = 0x3f3f3f3f;
#define MAX 2147483647
#define MIN -2147483647	
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define SIZE 100001;
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))

//global arrays 
int adj[300+3][300+3];
bool visited[300+3];
int parent[300+3];
bool AC[300+3];
int low[300+3];
int disc[300+3];
int timevalue=0;

//To find the articulation point in graph
 void DFS(int V,int vertex)
 {
 	visited[vertex]=true;
 	disc[vertex]=low[vertex]=timevalue;

 	timevalue=timevalue+1;

 	int child=0;

 	REP(i,0,V)
 	{
 		if(adj[vertex][i]!=0)
 		{
 			if(visited[i]==false)
 			{
 				// printf("%d \n",i );
 				child=child+1;
 				parent[i]=vertex;
 				DFS(V,i);
 			
 			low[vertex]=min(low[vertex],low[i]);
 			if(parent[vertex]==-1&&	child>1)
 			{
 				// printf("hi%d ",child );
 				AC[vertex]=true;
 			}

 			if(parent[vertex]!=-1&&low[i]>=disc[vertex])
 			{
 				AC[vertex]=true;
 			}

 			}
 			else if(parent[vertex]!=i)
 					 low[vertex]=min(low[vertex],disc[i]);
 		} 
 		
 	}
 }


void ACPOINT(int V)
{
	

	REP(i,0,V)
	{
		parent[i]=-1;
		visited[i]=false;
		low[i]=0;
		disc[i]=0;
		AC[i]=false;
	}
	//which stores, for every vertex v, the discovery timevalue of the earliest discovered vertex to which v
	// or any of the vertices in the subtree rooted at 
     //v is having a back edge. It is initialized by INFINITY.

	// discovery timevalue of every vertex. It is initialized by 0.

	REP(i,0,V)
	 	if(visited[i]==false)
			DFS(V,i);

	REP(i,0,V)
	{
		REP(j,0,V)
		printf("%d ",adj[i][j] );
		printf("\n");
	}
	printf("point\n");
	REP(i,0,V)
	{
		// printf("%d \n",parent[i] );
	if(AC[i]==true)
			printf("%d ",i );
	}
}

int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	//input vertex and edge
	int V,E;
	V=IN; 
	E=IN;
	//graph inputs u and v
	//adjacency is an N×N matrix denoting the adjacency matrix of the given graph.

	// printf("%d %d \n",V,E );
	REP(i,0,E)
	{
		int x,y;     
  		x=IN; 
  		y=IN;
		adj[x][y]=1;
		adj[y][x]=1;
	}
	ACPOINT(V);
	return 0;
}
