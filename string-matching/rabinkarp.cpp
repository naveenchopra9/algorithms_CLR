#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int prime=3;

long patternhash(char* arr,int end)
{
	long hash=0;
	for (int i = 0; i <= end; ++i)
	{
		hash+=arr[i]*pow(prime,i);
	}
	return hash;
}
long recalculate(char* txt,int txthash,int newindex,int oldindex,int patlen)
{
	long hash=txthash-txt[oldindex];
	hash=hash/prime;
	hash=hash+(txt[newindex]*pow(prime,patlen-1));

	return hash;
}
void search(char* txt ,char* pat)
{

	int n=strlen(txt);	
	int j=0,i=0,m=strlen(pat);
	long pathash=patternhash(pat,m-1);
	long txthash=patternhash(txt,m-1);
	cout<<"pathash:"<<pathash<<"txthash:"<<txthash<<endl;
	for (int i = 0; i <=n-m; ++i)
	{
		if(pathash==txthash)
		{
			for(j =0 ; j<m ; j++)
			{
				if(pat[j]!=txt[i+j])
					break;
			}
			if(j==m)
				cout<<"pattren found at:"<<i<<endl;

		}
			if(i<=n-m)
				txthash=recalculate(txt,txthash,i+m,i,m);

			cout<<txthash<<" "<<pathash<<endl;
	}
}
int main()
{
	char str1[100];
	char str2[100];
	cin>>str1>>str2;
	search(str1,str2);
}