#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void search(string str1 ,string str2)
{
	int l=str1.length();
	int j,i,m=str2.length();
	for (i = 0; i <= l-m; ++i)
	{
	  for ( j= 0; j< m; ++j)
	  {
	  	if(str1[i+j]!=str2[j])
	  	{
	  		break;
	  	}
	  }
	  if(j==m)
	  	cout<<"found at:"<<i<<endl;
	}
}
int main()
{
	string str1;
	string str2;
	cin>>str1>>str2;
	search(str1,str2);
}