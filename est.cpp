#include <iostream>
#include <climits>
#define V 5
using namespace std;
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
  int min = INT_MAX;
  int min_index;
 
  for (int v = 0; v < V; v++)
    // this part involve compare the adjacent node
    // and extract the minimum surrounding key
    if (mstSet[v] == false && key[v] <= min)
    {
       min = key[v];
       min_index = v;
     }
  return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
  cout << "Edge   Weight\n";
  for (int i = 1; i < V; i++)
    cout << parent[i] << " -> " << i << ' ' << graph[parent[i]][i] << endl;
}

void primMST(int graph[V][V])
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST
     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
     {
        key[i] = INT_MAX;
        mstSet[i] = false;
      }
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     //parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < V; count++)
     {
        int u = minKey(key, mstSet); // not included in mstSet and pick the minimum key
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          // connected and not self  not included before and ready to update the key value
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
            {
              parent[v]  = u;
              key[v] = graph[u][v];
            }
     }
     // print the constructed MST
     printMST(parent, V, graph);
}
// driver program to test above function
int main()
{
   // each entry stands for the weights
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};
    // Print the solution
  primMST(graph);
  return 0;
}









