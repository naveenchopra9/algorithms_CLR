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
	int top;
	unsigned stacksize;
	int* array;
};

struct Stack* createstack(unsigned capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));	
	stack->stacksize=capacity;
	stack->top=-1;	
	stack->array=(int*)malloc(stack->stacksize*sizeof(int));
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->stacksize-1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack*stack,int data)
{
	if(isFull(stack))
		return;
	stack->array[++stack->top]=data;
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return  0;
	return stack->array[stack->top--];

}

int main()
{
	int n;
	printf("Enter size of array::");
	scanf("%d",&n);
    struct Stack* stack=createstack(n);
    int a;
    cout<<"Enter elements in stack:";
    for (int i = 0; i < n; ++i)
    {
    	cin>>a;
    	push(stack,a);
    }
    cout<<endl;
    cout<<"Pop top integer:"<<pop(stack)<<endl;
    if(!isEmpty(stack))
    	cout<<"Stack not isEmpty"<<endl;
    if(!isFull(stack))
    	cout<<"Stack not Full"<<endl;
    return 0;
}