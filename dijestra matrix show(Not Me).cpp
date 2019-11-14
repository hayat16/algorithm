#include <stdio.h>
#include <limits.h>
#define V 5
#define INF 9999
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("The program is for adjacency matrix representation of the graph\n");
    printf("Vertex ||  Distance from Source  \n");
    for (int i = 0; i < V; i++)
    {
        printf("%d    to  %d \n", i, dist[i]);
    }
}

int main()
{int graph[V][V] = {{0,9,2,6,INF},
                      {INF,0,INF,INF,INF},
                      {INF,INF,0,3,1},
                      {INF,2,INF,0,INF},
                      {INF,INF,3,1,0}
                     };



    dijkstra(graph, 0);

    return 0;
}
