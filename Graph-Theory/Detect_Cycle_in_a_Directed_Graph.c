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


int  dfsutil(struct graph* graph ,int v,int white[],int gray[],int black[])
{
		    white[v]=1;
			gray[v]=2;
	       // printf("%d ",v);
            struct adjlistnode* node=graph->array[v].head;
     		while(node!=NULL)
     		{
    			int p;
    			p=node->data;
    			if(black[p]==3)
    			{
    					node=node->next;	
    					continue;
    			}
    			if(gray[p]==2)
    			 return 1;
    			if(white[node->data]==0)
    			{
    				
    				if(dfsutil(graph,p,white,gray,black))
    					return 1;
    			}
    	    	node=node->next;
    		}
    black[v]=3;
    return 0;
     
}
int dfs(struct graph* graph)
{
	int white[graph->size];
	int gray[graph->size];
	int black[graph->size];
	int temp=0;
	  for (int i = 0; i < graph->size; ++i)
	  {
	  	white[i]=0;
	  	gray[i]=0;
	  	black[i]=0;
	  }

 	 for (int i = 0; i < graph->size; ++i)
   		{

   		if(white[i]==0)
   				if(dfsutil(graph,i,white,gray,black))
   					{
   						temp++;
   					}
   }
   return temp;
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
    printf("AdjNodes-\n");
    printgraph(graph);
    printf("\n");
    printf("Number of cycles:%d",dfs(graph));
}
