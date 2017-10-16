#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int INF=999999;
int L[100][100];
int L1[100][100];
int L2[100][100];
int min(int a,int b)
{
	return (a>b)?b:a;
}
void extend_shortest_path(int W[][100],int n)
{
 for (int i = 0; i < n; ++i)
 {
 	for (int j = 0; j < n; ++j)
 	{
 		L2[i][j]=INF;
 		for (int k = 0; k < n; ++k)
 		{
 			L2[i][j]=min(L2[i][j],L1[i][k]+W[k][j]);
 		}
 		
 	}
 }
 for (int i = 0; i < n; ++i)
 {
 	for (int j = 0; j < n; ++j)
 	{
 		L1[i][j]=L2[i][j];
 	}
 }
}
void slow_all_pairs_shortest_path(int W[][100],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			L1[i][j]=W[i][j];
		}
	}
	for (int i = 2; i < n-1; ++i)
	{
		extend_shortest_path(W,n);
		printf("\n");
		printf("L-%d\n",i);
		for(int k = 0 ; k  < n ; k++)
		{
			for(int j = 0 ;  j< n ; j++)
			{
				if(L1[k][j]==INF)
					printf("INF ");
				else
				printf(" %d  ",L1[k][j] );
			}
			printf("\n");
		}
	}

}
int main()
{
	int n,e;
	cin>>n>>e;
	int a,b,w;
	int W[100][100];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			W[i][j]=INF;
		}
	}
	for (int i = 0; i <100; ++i)
	{
		W[i][i]=0;
	}

	for (int i = 0; i <e; ++i)
	{
		cin>>a>>b>>w;
		W[a-1][b-1]=w;
	}
	printf("L-1\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(W[i][j]==INF)
					printf("INF ");
				else
				printf(" %d  ",W[i][j] );
		}
		cout<<endl;
	}
	slow_all_pairs_shortest_path(W,n);
	return 0;
}
