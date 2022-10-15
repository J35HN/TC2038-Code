#include <vector>

using std::vector;

/**
 * @brief Floyd Warshall Algorithm. Finds the shortes distance between every pair of vertices
 * 
 * @param sourceNode Index value of the source node.
 * @return vector<vector<int>> A matrix with all distances from one node to another
 * Complexity: O(n^3), where n is the number of vertices.
 */
vector<vector<int>> floydAllPairsAlgorithm(vector<vector<int>> graph) {
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph.size(); j++) {
      for (int k = 0; k < graph.size(); k++) {
        // If there's an alternate path that is shorter than the current (if any)
        if ((graph[j][k] > (graph[j][i] + graph[i][k]) || graph[j][k] == -1) &&
            graph[j][i] != -1 && graph[i][k] != -1) {
          graph[j][k] = graph[j][i] + graph[i][k];
        }
      }
    }
  }

  return graph;
}