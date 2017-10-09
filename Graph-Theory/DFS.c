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
};




//ll node to store  a queue array
struct queuenode
{
	int value;
	struct queuenode* next;
};


//front store the first node of queue and rear store  last node of queue
struct queue
{
	struct queuenode *front,*rear;
};

struct queue* createqueue()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->front=q->rear=NULL;
	return q;
}


 void enqueue(struct queue* q,int key)
{
	//create a new node 
	struct queuenode* qnode=(struct queuenode*)malloc(sizeof(struct queuenode));
	qnode->value=key;	
	qnode->next=NULL;	
	//if queue is empty add front and rear both are same in queue
	if(q->rear==NULL)
	{
		q->front=q->rear=qnode;
		return;
	}
	//add at end of the queue  and  change the rear of the queue
	q->rear->next=qnode;
	q->rear=qnode;
}


//dequeue function  /remove key from queue
struct queuenode* dequeue(struct queue* q)
{
	//if queue is empty 
	if(q->front==NULL)
		return NULL;
	struct queuenode* temp=q->front;
	   q->front=q->front->next;
	 if(q->front==NULL)
	 	q->rear=NULL;
	 return temp;

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
void printgraph(struct graph* graph)
{
	for (int i = 0; i < graph->size; ++i)
	{
		struct adjlistnode* node=graph->array[i].head;
		printf("print-%dth head\n",i );
		while(node)
		{
			printf("%d-> ",node->data );
			node=node->next;
		}
		printf("\n");
	}
}

int time=0;
void dfsutil(struct graph* graph ,int v,int visit[],int d[],int f[])
{
	visit[v]=1;
	printf("%d ",v);
	time=time+1;
	d[v]=time;
    struct adjlistnode* node=graph->array[v].head;
    while(node!=NULL)
    {
    	int p;
    	p=node->data;
    	if(visit[node->data]==0)
    			{
    				
    				dfsutil(graph,p,visit,d,f);
    			}
    	    	node=node->next;
    }
    visit[v]=2;
    	time=time+1;
    	f[v]=time;
}
void dfs(struct graph* graph)
{
	int visit[graph->size];
	int d[graph->size];
	int f[graph->size];
  for (int i = 0; i < graph->size; ++i)
  {
  	visit[i]=0;
  }
   for (int i = 0; i < graph->size; ++i)
   {
   	if(visit[i]==0)
   		dfsutil(graph,i,visit,d,f);
   }
   printf("\n");
   for (int i = 0; i < graph->size; ++i)
   {
   	printf("s-%d f-%d v-%d\node",d[i],f[i],visit[i] );
   }
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
    for (int i = 0; i < m; ++i)
    {
      scanf("%d %d", &p,&q);
      addedge(graph,p,q);
    }
  
    printgraph(graph);
    dfs(graph);
}
