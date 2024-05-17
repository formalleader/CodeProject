#include <stdio.h>
void dijkstras(int wmat[10][10], int n, int s)
{
  int visited[10], distance[10];
  int cost[10][10];
  int nextnode;

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
    distance[i] = cost[s][i];
    visited[i] = 0;
  }

  distance[s] = 0;
  visited[s] = 1;
  int count = 1;

  while (count < n)
  {
    int mindistance = 9999;
    for (int i = 0; i < n; i++)
    {
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }
    }
    visited[nextnode] = 1;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        if (distance[i] > mindistance + cost[nextnode][i])
        {
          distance[i] = mindistance + cost[nextnode][i];
        }
      }
    }
    count++;
  }
  for (int i = 0; i < n; i++)
    if (i != s)
    {
      printf("\nDistance from source to %d: %d", i, distance[i]);
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
  dijkstras(graph, n, 0);
  return 0;
}