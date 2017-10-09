#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>	
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;
//create stack 

struct Stack
{
	int data;
	struct Stack* next;
};

struct Stack* createnode(int data)
{
	struct Stack* newnode=(struct Stack*)malloc(sizeof(struct Stack));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

int isEmpty(struct Stack* root)
{
	return !root;
}

void push(struct Stack** root,int data)
{
	struct Stack* stacknode=createnode(data);
	stacknode->next=*root;
	*root=stacknode;
}

int pop(struct Stack** root)
{
	if(isEmpty(*root))
		return 0;
	struct Stack* temp=*root;
	(*root)=(*root)->next;
	int value=temp->data;
	free(temp);
	return value;
}
int peek(struct Stack* root)
{
 if(isEmpty(root))
 	return 0;
  return root->data;
}
int main()
{
	int n;
	printf("Enter size of array::");
	scanf("%d",&n);
    struct Stack* root=NULL;
    int a;
    cout<<"Enter elements in stack:";
    for (int i = 0; i < n; ++i)
    {
    	cin>>a;
    	push(&root,a);
    }
    cout<<endl;
    cout<<"Pop top integer:"<<pop(&root)<<endl;
    if(!isEmpty(root))
    	cout<<"Stack not isEmpty"<<endl;

    	cout<<"Top value:"<<peek(root)<<endl;
    return 0;
}