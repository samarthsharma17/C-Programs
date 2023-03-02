#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

int V;

int min_distance(int dist[],bool sptSet[])
{
    int min = INT_MAX;
    int min_index;

    for(int v=0;v<V;v++)
    {
        if(sptSet[v]==false && dist[v]<=min)
        {
            min=dist[v];
            min_index=v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from source\n");

    for(int v=0;v<V;v++)
    {
        printf("%d \t\t %d\n",v,dist[v]);
    }
}


void dij(int graph[V][V],int src)
{
    // for(int i=0;i<V;i++)
    // {
    //     for(int j=0;j<V;j++)
    //     {
    //         printf("%d\t",graph[i][j]);
    //     }
    //     printf("\n");
    // }
    int dist[V];

    bool sptSet[V];

    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<V-1;i++)
    {
        int u = min_distance(dist,sptSet);

        sptSet[u]=true;

        for(int v=0;v<V;v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]= dist[u]+graph[u][v];
            }
        }
    }

    printSolution(dist);

}

int main()
{
   int src;
    
    printf("Enter number of nodes\n");
    scanf("%d",&V);

    int graph[V][V];
    printf("Enter the source vertex\n");
    scanf("%d",&src);

    printf("Enter the graph\n");

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    // int graph[V][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dij(graph,src);
    
}