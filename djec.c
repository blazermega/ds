#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void djek(int V[MAX][MAX],int n);

int main()
{
    int n;
    printf("enter number of nodes:");
    scanf("%d",&n);
    int V[MAX][MAX];
    printf("enter the adj matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&V[i][j]);
        }
    }
    djek(V,n);
}

void djek(int V[MAX][MAX],int n)
{
    int f,l;
    printf("enter start and end nodes:\n");
    scanf("%d%d",&f,&l);
    int dist[n] = {-1};
    dist[f] = 0;
    int front=0,rear=0;
    int q[n];
    q[rear] = f;
    while(front<=rear)
    {
        
    }

}