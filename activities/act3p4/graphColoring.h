#include <vector>
#include <utility>
#include <iostream>

using std::vector;
using std::pair;
using namespace std;


/**
 * @brief Merge algorithm from Merge Sort. Sorts from largest to smallest.
 * 
 * @param numbers Vector of integer tuples, where we sort merge evaluating the second integer in the pair.
 * @param left Value of the left limit index.
 * @param middle Value of the middle index.
 * @param right Value of the right limit index.
 * @return vector<pair<int, int>> A vector of integer tuples sorted.
 * Complexity: O(n).
 */
vector<pair<int, int>> merge(vector<pair<int, int>> & numbers, int left, int middle, int right) {
    int leftLimit = middle - left + 1;
    int rightLimit = right - middle;

    vector<pair<int, int>> leftVector, rightVector;

    for (int i = 0; i < leftLimit; i++) {
        leftVector.push_back(numbers[left + i]);
    }
    for (int j = 0; j < rightLimit; j++) {
        rightVector.push_back(numbers[middle + 1 + j]);
    }

    int indexLeft = 0, indexRight = 0;
    int indexMerged = left;

    while (indexLeft < leftLimit && indexRight < rightLimit) {
        if (leftVector[indexLeft].second >= rightVector[indexRight].second) {
            numbers[indexMerged] = leftVector[indexLeft];
            indexLeft++;
        } else {
            numbers[indexMerged] = rightVector[indexRight];
            indexRight++;
        }
        indexMerged++;
    }

    while (indexLeft < leftLimit) {
        numbers[indexMerged] = leftVector[indexLeft];
        indexLeft++;
        indexMerged++;
     }
  
    while (indexRight < rightLimit) {
        numbers[indexMerged] = rightVector[indexRight];
        indexRight++;
        indexMerged++;
    }
    return numbers;
}

/**
 * @brief Merge Sort algorithm. Divides the list into sub-vectors, and sorts from largest to smallest.
 * 
 * @param numbers Vector of integer tuples.
 * @param left Value of the starting index of the vector.
 * @param right Value of the last index of the vector.
 * @return vector<pair<int, int>> 
 * Complexity: O (log(n)).
 */
vector<pair<int, int>> mergeSort(vector<pair<int, int>> & numbers, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(numbers, middle + 1, right);
        mergeSort(numbers, left, middle);
        merge(numbers, left, middle, right);
    }
    return numbers;
}

/**
 * @brief Finds the degree value of nodes in a adyacent matrix graph.z
 * 
 * @param graph Matrix of the graph.
 * @return vector<pair<int, int>> Vector of tuples ordered from higher to lower degree value corresponding to the index node.
 * Complexity: O(log(n) + n^2).
 */
vector<pair<int, int>> sortByDegree(vector<vector<int>> graph){
  vector<pair<int, int>> results;
  // Traverse each node.
  for(int i = 0; i < graph.size(); i++){
    int degree = 0;
    // Add the corresponding value conections to degree.
    for(int j = 0; j < graph.size(); j++){
      degree += graph[i][j];
    }
    // Add into a tuple the index value of the node and the degree value.
    pair<int, int> newPair = {i, degree};
    results.push_back(newPair);
  }
  // Sort from largest to smalles value in degree.
  results = mergeSort(results, 0, results.size());
  return results;
}

/**
 * @brief Colors a graph (adyacent matirx) with the least amount of colors.
 *
 * @param graph Matrix of the graph.
 * Average Complexity: O(n^2). Worst Case: O(n^3)  
 */
void graphColoring(vector<vector<int>> graph){
  // Init vector of tuples. First value is the index of a node, second values it's their degree.
  vector<pair<int, int>> degrees = sortByDegree(graph);
  vector<int> colors (graph.size(), -1);
  int currentLastColor = 1;
  // Iterate each node.
  for(int i = 0; i < graph.size(); i++){
    cout << degrees[i].first;
    if(colors[degrees[i].first] == -1){ // Assing color to i index if color in index i is -1.
      colors[degrees[i].first] = currentLastColor;
      currentLastColor++;
      for(int j = 0; j < graph[degrees[i].first].size(); j++){
        // If the node isn't colored and is not connected to the pivot.
        if(colors[j] == -1 && graph[degrees[i].first][j] == 0){
          bool isValidToColor = true;
          // Check if there's other node with the same color connected to the node index i.
          for(int k = 0; k < graph.size(); k++){
            if(colors[k] == colors[degrees[i].first] && graph[j][k] == 1){
              isValidToColor = false;
            }
          }
          if(isValidToColor){
            colors[j] = colors[degrees[i].first];
          }
        }
      }
    }
  }

  for(int k = 0; k < colors.size(); k++){
    cout << "Node: " << k+1 << ", Assigned Color: " <<colors[k] << endl;
  }
}