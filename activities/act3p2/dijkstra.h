#include <vector>
#include <limits.h>

using std::vector;

int INF = INT_MAX;

/**
 * @brief Returns the index of the nearest node (lesser distance) if it has not been visited.
 * 
 * @param totalNodes The total number of nodes in the graph.
 * @param visitedNodes Array (bool) of visited nodes.
 * @param distances Array of the distances from source node to the rest.
 * @return int The index of the nearest node.
 * Complexity: O(n), where n is the number of nodes (vertices).
 */
int obtainNearestNode(int totalNodes, vector<bool> visitedNodes, vector<int> distances)
{
  int minDistance = INF;
  int nearestNode = 0;
  // Iterate to each node, to determine which one is the closest one.
  for (int i = 0; i < totalNodes; i++)
  {
    // Check that the node has not been visited.
    if (visitedNodes[i] != true && (distances[i] <= minDistance) && distances[i] != -1)
    {
      minDistance = distances[i];
      nearestNode = i;
    }
  }
  return nearestNode;
}

/**
 * @brief Dijkstra algorithm. Finds the shortes path from a source node, to the rest of nodes in a graph.
 * 
 * @param graph A matrix of adjacencies that represent a graph with direction.
 * @param sourceNode Index value of the source node.
 * @return vector<int> An arrays with the corresponding shortest distances from source index to index node.
 * Complexity: O(V^2), where V is the number of vertices.
 *  Could have a better computational complexity, if we had implemented a Min. Heap.
 */
vector<int> dijkstraAlgorithm(vector<vector<int>> graph, int sourceNode){
  vector<int> distanceResults(graph[0].size(), INF); // Distance values from source node to each index node.
  vector<bool> visitedNodes (graph[0].size(), false); // Array to keep track of visited nodes.
  distanceResults[sourceNode] = 0; // Distance from source node to itself is 0.
  // Iterate to each node and calculate its distance.
  for (int i = 0; i < graph[0].size(); i++)
  {
    int nearestNode = obtainNearestNode(graph[0].size(), visitedNodes, distanceResults);
    visitedNodes[nearestNode] = true; // Mark the node obtained as visited.
    // Visit adjacent nodes to our nearest node obtained.
    for (int j = 0; j < graph[0].size(); j++)
    {
      // Examine that it is an adjacent node, and only update if our new distance to the next node is lower than previous.
      if ((graph[nearestNode][j] != -1 && distanceResults[nearestNode] != INF)&&distanceResults[j] > distanceResults[nearestNode] + graph[nearestNode][j])
      {
        distanceResults[j] = distanceResults[nearestNode] + graph[nearestNode][j]; // Update value.
      }
    }
  }
  // Change INF values to -1.
  for (int i = 0; i < distanceResults.size(); i++)
  {
    if (distanceResults[i] == INF)
    {
      distanceResults[i] = -1;
    }
  }
  return distanceResults;
}