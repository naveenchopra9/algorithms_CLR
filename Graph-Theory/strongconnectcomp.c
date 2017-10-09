#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//represent structure of  adj list node
struct adjlistnode
{
  int data;
  struct adjlistnode* next;
};
//represent struct of adj  list
struct adjlist
{
	struct adjlistnode* head;//pointer  to head node of list
};
struct graph
{
	int size;
	struct adjlist *array;
	struct adjlist *backarray;
};

//create stack 

struct Stack
{
	int top;
	unsigned stacksize;
	int* array;
};

int time =0,tempcount=0;
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

struct graph* creategraph(int n)
{
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	graph->size=n;
	graph->array=(struct adjlist*)malloc(n*sizeof(struct adjlist));
	graph->backarray=(struct adjlist*)malloc(n*sizeof(struct adjlist));
	int i;
	for ( i = 0; i < n; ++i)
	{
	  graph->array[i].head=NULL;
	  graph->backarray[i].head=NULL;
	}
	return graph;
}

void addedge(struct graph* graph,int u,int v)
{
	//adjancency v to u;
	struct adjlistnode *newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->data=v;
	newnode->next=NULL;
	newnode->next=graph->array[u].head;
	graph->array[u].head=newnode;
	struct adjlistnode *newnode1=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode1->data=u;
	newnode1->next=NULL;
	newnode1->next=graph->backarray[v].head;
	graph->backarray[v].head=newnode1;	

}


void printgraph(struct graph* graph)
{
    
	for (int i = 0; i < graph->size; ++i)
	{
		struct adjlistnode* node=graph->array[i].head;
		printf(" %dth head :",i );
		while(node)
		{
			printf("%d-> ",node->data );
			node=node->next;
		}
		printf("\n");
	}

	printf("print backarray\n");
	for (int i = 0; i < graph->size; ++i)
	{
		struct adjlistnode* node=graph->backarray[i].head;
		printf("%dth head:",i );
		while(node)
		{
			printf("%d-> ",node->data );
			node=node->next;
		}
		printf("\n");
	}
}
void dfsutil(struct graph* graph ,int v,int visit[],int d[],int f[],struct Stack* stack)
{
	visit[v]=1;
	time=time+1;
	d[v]=time;
    struct adjlistnode* node=graph->array[v].head;
    while(node!=NULL)
    {
    	int p;
    	p=node->data;
    	if(visit[node->data]==0)
    			{
    				
    				dfsutil(graph,p,visit,d,f,stack);
    			}
    	    	node=node->next;
    }
    push(stack,v);
      visit[v]=2;
    	time=time+1;
    	f[v]=time;
}


void dfsutil1(struct graph* graph ,int v,int visit[])
{
	visit[v]=1;
	tempcount++;

    struct adjlistnode* node=graph->backarray[v].head;
    while(node!=NULL)
    {
    	int p;
    	p=node->data;
    	if(visit[node->data]==0)
    			{		
    		dfsutil1(graph,p,visit);
    			}
    	    	node=node->next;
    }

}



void dfs(struct graph* graph)
{
	int visit[graph->size];
	int d[graph->size];
	int f[graph->size];
	int count=0;

    struct Stack* stack=createstack(graph->size);
	  for (int i = 0; i < graph->size; ++i)
	  {
	  	visit[i]=0;
	  }

   for (int i = 0; i < graph->size; ++i)
   {
   	if(visit[i]==0)
   	{
   		dfsutil(graph,i,visit,d,f,stack);
   		count++;
   	}	
   }   
   printf("\n");
   for (int i = 0; i < graph->size; ++i)
   {
   	printf("\nstart time-%d final time-%d\n",d[i],f[i]);
   }

   	for (int i = 0; i <graph->size; ++i)
	{
		visit[i]=0;
	}
	int maxcount=-1;
   while(!isEmpty(stack))
   {
   	int p=pop(stack);
   	if(visit[p]==0)
   	{
   		tempcount=0;

   		dfsutil1(graph,p,visit);
   		if(maxcount<tempcount)
   		{
 		maxcount=tempcount;
   		
   		}
   		
   	}
   }
   printf("Maximum strong connected :%d \n",maxcount );
}
int main()
{
	int n;
	printf("Enter size of array::");
	scanf("%d",&n);
	struct graph* graph=creategraph(n);
	int m;
	printf("Enter number of edges:");
	scanf("%d",&m);
	int p,q;
	printf("Enter v to u:");
    for (int i = 0; i < m; ++i)
    {
      scanf("%d %d", &p,&q);
      addedge(graph,p,q);
    }
  	
    printgraph(graph);

    dfs(graph);
}
