
#include <iostream>
#include <climits>
using namespace std;
// Number of vertices in the graph
#define V 9
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minKey(int key[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX; 
   int min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && key[v] <= min)
    {
      min = key[v];
      min_index = v;
    }
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(int key[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, key[i]);
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int key[V];     // The output array.  key[i] will hold the shortest
                     // distance from src to i
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
     {
        key[i] = INT_MAX; 
        sptSet[i] = false;
     }
     // Distance of source vertex from itself is always 0
     key[src] = 0;
     // Find shortest path for all vertices
     for (int count = 0; count < V - 1; count++)
     {
       int u = minKey(key, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
        //     not included before   connected and not self   
        if (sptSet[v] == false && graph[u][v] && key[u] + graph[u][v] <= key[v])
        {
            cout << key[v] << endl;
            key[v] = key[u] + graph[u][v];
        }
     }
     printSolution(key, V);
}

// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

  
    dijkstra(graph, 0);
  
    return 0;
}