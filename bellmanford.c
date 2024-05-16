#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph
#define E 8 // Number of edges in the graph

// Structure to represent an edge
struct Edge
{
  int src, dest, weight;
};

// Function to find the shortest path from src to all other vertices using Bellman-Ford algorithm
void bellmanFord(struct Edge edges[], int src)
{
  int dist[V];

  // Initialize distances from source to all other vertices as INFINITE
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  // Relax all edges |V| - 1 times
  for (int i = 0; i < V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = edges[j].src;
      int v = edges[j].dest;
      int weight = edges[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight;
    }
  }

  // Check for negative weight cycles
  for (int i = 0; i < E; i++)
  {
    int u = edges[i].src;
    int v = edges[i].dest;
    int weight = edges[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
    {
      printf("Graph contains negative weight cycle\n");
      return;
    }
  }

  // Print the shortest distances
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < V; i++)
  {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

int main()
{
  // Example graph
  struct Edge edges[E] = {
      {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

  printf("Bellman-Ford Algorithm:\n");
  bellmanFord(edges, 0); // Source vertex is 0

  return 0;
}
