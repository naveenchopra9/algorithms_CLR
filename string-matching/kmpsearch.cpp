#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void patpreffix(char* pat,int arr[])
{
	int len=strlen(pat);
	int j=0;
	int i =1;
    arr[0]=0;
		while(i<len)
		{
			if(pat[i]==pat[j])
			{
				arr[i]=j+1;
				i++;
				j++;
			}
			else
			{
				if(j!=0)
					j=arr[j-1];
				else
				{
					arr[i]=0;
					i++;
				}
			}
		}
}
int kmp(char* txt,char* pat)
{
	int arr[strlen(pat)];
	 patpreffix(pat,arr);
	 int i =0;
	 int temp=0;
	 int j=0;
	 while(i<strlen(txt)&&j<strlen(pat))
	 {
	 	if(txt[i]==pat[j])
	 	{
	 		i++;
	 		j++;

	 	}
	 	else
	 	{
	 		if(j!=0)
	 			j=arr[j-1];
	 		else
	 			i++;	
	 	}
	 	if(j==strlen(pat))
	 	{
	 		temp++;
	 		j=0;
	 		i=i-strlen(pat)+1;
	 	}
	 }
	 if(temp>0)
	 	return temp;
	 return -1;
}
int main()
{
	char str1[100];
	char str2[100];
	cin>>str1>>str2;
	cout<<kmp(str1,str2);
}