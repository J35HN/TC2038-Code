#include <vector>
#include <limits.h>

using std::vector;

int INF = INT_MAX;

int obtainNearestNode(int totalNodes, vector<bool> visitedNodes, vector<int> distances)
{
  int minDistance = INF;
  int nearestNode = 0;
  for (int i = 0; i < totalNodes; i++)
  {
    if (visitedNodes[i] != true && ( distances[i] < minDistance))
    {
      minDistance = distances[i];
      nearestNode = i;
    }
  }
  return nearestNode;
}

vector<int> dijkstraAlgorithm(vector<vector<int>> graph, int sourceNode){
  vector<int> distanceResults(graph[0].size(), INF); // Distance values from source node to each index node.
  vector<bool> visitedNodes (graph[0].size(), false); // Array to keep track of visited nodes.
  distanceResults[sourceNode] = 0; // Distance from source node to itself is 0.
  // Iterate to each node and calculate its distance.
  for (int i = 0; i < graph[0].size(); i++)
  {
    int nearestNode = obtainNearestNode(graph[0].size(), visitedNodes, distanceResults);
  }

  return distanceResults;
}