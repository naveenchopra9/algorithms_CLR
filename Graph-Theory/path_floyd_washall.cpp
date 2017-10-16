#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int INF=999999;
int L1[100][100];
int L2[100][100];
int min(int a,int b)
{
	return (a>b)?b:a;
}
void slow_all_pairs_shortest_path(int W[][100],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			L1[i][j]=W[i][j];
			if(W[i][j]==INF||i==j)
				L2[i][j]=-1;
			else if(W[i][j]<INF&&i!=j)
				L2[i][j]=i+1;
		}
	}
	printf("\n");
	printf("Predecessor matrix\n\n");
	for(int k = 0 ; k  < n ; k++)
		{
			for(int j = 0 ;  j< n ; j++)
			{
				if(L2[k][j]==-1)
					printf("%5s","NIL");
				else
				printf("%5d",L2[k][j] );
			}
			printf("\n");
		}	

printf("\n");

		for(int k =0 ; k< n ; k++)
		{
			for(int i = 0 ; i < n ; i++ )
			{
				for(int j =0 ; j < n ; j++)
				{
					if(L1[i][j]<=(L1[i][k]+L1[k][j]))
						   L2[i][j]=L2[i][j];
						else
						{
							 L2[i][j]=L2[k][j];	
						}
					L1[i][j]=min(L1[i][j],L1[i][k]+L1[k][j]);

				}
			}
		printf("L-%d\n",k+1);
		for(int l = 0 ; l  < n ; l++)
		{
			for(int m = 0 ;  m< n ; m++)
			{
				if(L1[l][m]>=INF-100)
					printf("%5s","INF");
				else
				printf("%5d",L1[l][m] );
			}
			printf("\n");
		}

		printf("\n\n");
		printf("Predecessor matrix\n\n");
		for(int l = 0 ; l  < n ; l++)
		{
			for(int m = 0 ;  m< n ; m++)
			{
				if(L2[l][m]==-1)
					printf("%5s","NIL");
				else
				printf("%5d",L2[l][m] );
			}
			printf("\n");
		}
		printf("\n\n");
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
	printf("\n");
	slow_all_pairs_shortest_path(W,n);
	return 0;
}
/*input
5 9
1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
4 3 -5
4 1 2
5 4 6
*/
/*
output
L-1
 0   3   8  INF  -4  
INF  0  INF  1   7  
INF  4   0  INF INF 
 2  INF  -5   0  INF 
INF INF INF  6   0  


Predecessor matrix

  NIL    1    1  NIL    1
  NIL  NIL  NIL    2    2
  NIL    3  NIL  NIL  NIL
    4  NIL    4  NIL  NIL
  NIL  NIL  NIL    5  NIL

L-1
    0    3    8  INF   -4
  INF    0  INF    1    7
  INF    4    0  INF  INF
    2    5   -5    0   -2
  INF  INF  INF    6    0


Predecessor matrix

  NIL    1    1  NIL    1
  NIL  NIL  NIL    2    2
  NIL    3  NIL  NIL    1
    4    1    4  NIL    1
  NIL  NIL  NIL    5  NIL


L-2
    0    3    8    4   -4
  INF    0  INF    1    7
  INF    4    0    5   11
    2    5   -5    0   -2
  INF  INF  INF    6    0


Predecessor matrix

  NIL    1    1    2    1
  NIL  NIL  NIL    2    2
  NIL    3  NIL    2    2
    4    1    4  NIL    1
  NIL  NIL  NIL    5  NIL


L-3
    0    3    8    4   -4
  INF    0  INF    1    7
  INF    4    0    5   11
    2   -1   -5    0   -2
  INF  INF  INF    6    0


Predecessor matrix

  NIL    1    1    2    1
  NIL  NIL  NIL    2    2
  NIL    3  NIL    2    2
    4    3    4  NIL    1
  NIL  NIL  NIL    5  NIL


L-4
    0    3   -1    4   -4
    3    0   -4    1   -1
    7    4    0    5    3
    2   -1   -5    0   -2
    8    5    1    6    0


Predecessor matrix

  NIL    1    4    2    1
    4  NIL    4    2    1
    4    3  NIL    2    1
    4    3    4  NIL    1
    4    3    4    5  NIL


L-5
    0    1   -3    2   -4
    3    0   -4    1   -1
    7    4    0    5    3
    2   -1   -5    0   -2
    8    5    1    6    0


Predecessor matrix

  NIL    3    4    5    1
    4  NIL    4    2    1
    4    3  NIL    2    1
    4    3    4  NIL    1
    4    3    4    5  NIL


*/
