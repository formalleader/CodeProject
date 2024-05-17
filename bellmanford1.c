#include <stdio.h>
void bellmanford(int wmat[10][10], int n, int s)
{
  int distance[10], cost[10][10];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (wmat[i][j] == 0)
      {
        cost[i][j] = 9999;
      }
      else
      {
        cost[i][j] = wmat[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    distance[i] = 9999;
  }
  distance[s] = 0;
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (distance[j] > distance[i] + cost[i][j])
        {
          distance[j] = distance[i] + cost[i][j];
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("Shortest distance to node %d: %d\n", i, distance[i]);
  }
}
int main()
{
  int graph[10][10] = {
      {0, 4, 2, 0, 0},
      {0, 0, 5, 10, 0},
      {0, 0, 0, 3, 0},
      {0, 0, 0, 0, 7},
      {0, 0, 0, 0, 0}};
  int n = 5;
  bellmanford(graph, n, 0);
  return 0;
}