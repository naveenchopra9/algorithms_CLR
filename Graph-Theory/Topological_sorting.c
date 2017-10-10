//topological sorting of  0 to n-1 vertices
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
	struct adjlist *array;//adj list of any vertices
};

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


struct graph* creategraph(int n)
{
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	graph->size=n;
	graph->array=(struct adjlist*)malloc(n*sizeof(struct adjlist));
	int i;
	for ( i = 0; i < n; ++i)
	{
	  graph->array[i].head=NULL;
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

}

void topologicalutil(struct graph* graph ,int v,int visit[],struct Stack* stacknode)
{
	visit[v]=1;
    struct adjlistnode* node=graph->array[v].head;
    while(node!=NULL)
    {
    	int p;
    	p=node->data;
    	if(visit[node->data]==0)
    			{
    				
    				topologicalutil(graph,p,visit,stacknode );
    			}

    	    	node=node->next;
    }

    push(stacknode,v); 
}


void topological(struct graph* graph)
{
	int visit[graph->size];
	struct Stack* stacknode=createstack(graph->size);

	  for (int i = 0; i < graph->size; ++i)
	  {
	  	 visit[i]=0;
	  }
	   for (int i = 0; i < graph->size; ++i)
	   {
	   	   if(visit[i]==0)
	   	   {
	   		  topologicalutil(graph,i,visit,stacknode);
	   	   }
	   }
	   printf("\nTopological order:");
	   while(!isEmpty(stacknode))
	   {
	   		printf("%d  ", pop(stacknode));
	   }
}

int main()
{
	int n;
	printf("Enter size of vertices::");
	scanf("%d",&n);
	struct graph* graph=creategraph(n);
	int m;
	printf("Enter number of edges:");
	scanf("%d",&m);
	int p,q;
    for (int i = 0; i < m; ++i)
    {
      scanf("%d %d", &p,&q);
      addedge(graph,p,q);
    }
    topological(graph);
}
