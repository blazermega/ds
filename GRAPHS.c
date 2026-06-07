#include<stdio.h>
#include<stdlib.h>

struct graph
{
    int data;
    int bfs,dfs;
    struct graph *next;
};
typedef struct graph graph;

/*struct list
{
    graph data;
    struct list *next;
};*/
//typedef struct list list;
int exist(graph **list,int data);
void push(graph* head,graph* new);

void bfs(graph** list);
void dfs(graph** list);
int main()
{
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    graph** list = (graph**)malloc(sizeof(graph*)*n);
    for(int i=0;i<n;i++)
    {
        list[i] = (graph*)malloc(sizeof(graph));
        printf("Enter the data of node %d\n", i+1);
        scanf("%d",&list[i]->data);
        list[i]->next = NULL;
        list[i]->bfs = 0;
        list[i]->dfs = 0;
    }

    for(int i=0;i<n;i++)
    {
        char op;
        printf("enter adjecent nodes of %d", list[i]->data);
        do
        {
            int data;
            printf("enter the node\n");
            scanf("%d",&data);
            int j = exist(list,data);
            if (j != -1)
            {
                push(list[i], list[j]);
            }
            else
            {
                printf("node does not exist\n");
            }
            printf("add another node(y/n)\n");
            scanf("%c",&op);

        }while(op=='y' || op=='Y');
    }
    bfs(list);
    dfs(list);
}

int exist(graph **list,int data)
{
    
}