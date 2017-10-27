#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define SIZE 10002
#define IN ({int n; scanf("%d", &n);	n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
#define f first
#define s second
#define pb push_back	
const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
vector < int >adj[SIZE];

void topological(int v,vi indegree,vi res,bool visit[])
{
	bool f = false;
	REP(i,0,v)
	{
		if(indegree[i]==0 && !visit[i])
		{
			res.pb(i);
			visit[i]=true;
			vi :: iterator it;
			for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
			{
				indegree[*it]--;
			}

			topological(v,indegree,res,visit);

			visit[i]=false;
			res.erase(res.end() - 1);
			for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
			{
				indegree[*it]++;
			}
			f=true;
		}
	}
	if(!f)
	{
		REP(i,0,res.size())
		{
			printf("%d ",res[i] );
		}
		printf("\n");
	}
}	
int main(int argc, char const *argv[])
{
	int v;
	int e;
	v=IN;
	e=IN;
	vi indegree(v,0);
	REP(i,0,e)
	{
		int x,y;
		x=IN; y=IN;
		adj[x].pb(y);
		indegree[y]++;
	}
	REP(i,0,v)
		printf("%d\n",indegree[i] );
	vi res;
	bool visit[v];
	memset(visit,false,sizeof(visit));
	printf("ALL possiable topological:\n");
	topological(v,indegree,res,visit);
	return 0;
}
