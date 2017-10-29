// visited timevalue <=low timevalue of adj vertex	
/*brute code
function find_bridges(adj[][], V, Edge[], E, isBridge[])
    for i = 0 to E
        adj[Edge[i].u][Edge[i].v]=adj[Edge[i].v][Edge[i].u]=0
        for j = 0 to V
            visited[j] = false
        Queue.Insert(Edge[i].u])
        visited[Edge[i].u] = true
        check = false
        while Queue.isEmpty() == false
            x = Queue.top()
            if x == Edge[i].v
                check = true
                BREAK
            Queue.Delete()
            for j = 0 to V
                if adj[x][j] == true AND visited[j] == false
                    Queue.insert(j)
                    visited[j] = true
        adj[Edge[i].u][Edge[i].v]=adj[Edge[i].v][Edge[i].u]=1
        if check == false
            isBridge[i] = true

            */
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
int timevalue =0;
//To find the articulation bridge in graph
 void DFS(int V,int vertex)
 {
 	visited[vertex]=true;
 	
 	disc[vertex]=low[vertex]=timevalue;

 	timevalue=timevalue+1;

 	REP(i,0,V)
 	{
 		if(adj[vertex][i]!=0)
 		{
 			if(visited[i]==false)
 			{
 				parent[i]=vertex;
 				DFS(V,i);

 			 low[vertex]=min(low[vertex],low[i]);

	 			if(low[i]>disc[vertex])
	 			{
	 				printf("\n%d %d\n ",vertex,i );
	 			}
 			}
 			else if(parent[vertex]!=i)
 					 low[vertex]=min(low[vertex],disc[i]);
 		} 
 		
 	}
 }


void ACPOINT(int V)
{
	Set(visited,false);
	REP(i,0,V)
		parent[i]=-1;
	Set(AC,false);
	//which stores, for every vertex v, the discovery timevalue of the earliest discovered vertex to which v
	// or any of the vertices in the subtree rooted at 
     //v is having a back edge. It is initialized by INFINITY.


	Set(low,0);
	// discovery timevalue of every vertex. It is initialized by 0.
	Set(disc,0);
	printf("graph\n");
	REP(i,0,V)
	{
		REP(j,0,V)
		printf("%d ",adj[i][j] );
		printf("\n");
	}
	printf("bridge\n");
	REP(j,0,V)
		DFS(V,j);
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
