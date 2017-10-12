#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <map>
#include <cstdlib>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX=10001;
int temp =0;
void intialize(int arr[],int size[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i]=i;
		size[i]=1;
	}
}
vector<int> display( map<int,unsigned int> counts )
{
		vector<int>p;
		map <int,unsigned int>::iterator count;
		 for ( count = counts.begin(); count != counts.end(); ++count) 
		 {
 			temp++;
		 	p.push_back(count->second);
         }
         return p;
}
map<int,unsigned int> counter(vector<int>& vec)
{
	map<int,unsigned int> rv;
		 vector<int>::iterator val;
	   for (val = vec.begin(); val != vec.end(); ++val)
	    {
        rv[*val]++;
        }
    return rv;
}
   //finding root of an element
int root(int arr[],int x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;

}

void weight_union(int arr[],int size[],int n,int x,int y)
{
	//cout<<"x"<<x<<"y"<<y<<endl;
	int p=arr[x];
	int q=arr[y];
	int rootx=root(arr,x);
	int rooty=root(arr,y);
	//cout<<endl;
	//cout<<"x"<<rootx<<"y"<<rooty<<endl;
	if(size[rootx]<size[rooty])
	{
		for(int t =1	 ; t<n ; t++)
			    if(arr[t]==p)
		         arr[t]=arr[rooty];
		size[rooty]+=size[rootx];
	}
	else
	{
		for(int t =1 ; t<n ; t++)
			    if(arr[t]==q)
					arr[t]=arr[rootx];
		size[rootx]+=size[rooty];
	}
	//	cout<<endl;
	vector<int> mem;
	vector<int> vec1;
	temp=0;
	for (int i = 1; i < n; ++i)
	{
		//cout<<arr[i]<<" "<<size[i]<<endl;
		mem.push_back(arr[i]);
	}
	vec1=display(counter(mem));
	sort(vec1.begin(),vec1.end());
	vector<int>:: iterator it;
	for(it=vec1.begin(); it!=vec1.end(); it++)
		cout<<*it<<" ";
		cout<<endl;
}
int main()
{
	int arr[MAX];
	int size[MAX];
	
	int m,n;
	
	cin>>n>>m;
	
	intialize(arr,size,n+1);
	int x,y;
	for (int i = 0; i <m; ++i)
	{
		cin>>x>>y;
		weight_union(arr,size,n+1,x,y);
	}
}
