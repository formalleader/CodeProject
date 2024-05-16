#include <stdio.h>
#include <limits.h>

#define V 9 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value, from the set of vertices
int minDistance(int dist[], int visited[])
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
  {
    if (!visited[v] && dist[v] <= min)
    {
      min = dist[v];
      min_index = v;
    }
  }

  return min_index;
}

// Function to print the shortest path from source to j using parent array
void printPath(int parent[], int j)
{
  if (parent[j] == -1)
    return;

  printPath(parent, parent[j]);
  printf("%d -> ", j);
}

// Function to print the solution
void printSolution(int dist[], int n, int parent[])
{
  int src = 0;
  printf("Vertex\t Distance\tPath\n");
  for (int i = 1; i < V; i++)
  {
    printf("%d -> %d \t %d\t\t%d ", src, i, dist[i], src);
    printPath(parent, i);
    printf("\n");
  }
}

// Function to implement Dijkstra's algorithm for a given graph
void dijkstra(int graph[V][V], int src)
{
  int dist[V];    // Array to store the shortest distances from src to i
  int visited[V]; // Array to mark visited vertices
  int parent[V];  // Array to store the shortest path tree

  // Initialize all distances as infinite and visited[] as false
  for (int i = 0; i < V; i++)
  {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }

  // Distance of source vertex from itself is always 0
  dist[src] = 0;
  parent[src] = -1;

  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++)
  {
    int u = minDistance(dist, visited); // Pick the minimum distance vertex from the set of vertices not yet processed
    visited[u] = 1;                     // Mark the picked vertex as visited

    // Update dist[] value of the adjacent vertices of the picked vertex
    for (int v = 0; v < V; v++)
    {
      if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }

  // Print the constructed distance array
  printSolution(dist, V, parent);
}

int main()
{
  int graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},
      {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},
      {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0},
      {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},
      {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};

  printf("Shortest Path Calculation using Dijkstra's Algorithm:\n");
  dijkstra(graph, 0);

  return 0;
}
