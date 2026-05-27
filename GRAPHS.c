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
            if (exist(list,data))

        }
    }

}