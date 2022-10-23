#include <vector>
#include <utility>
#include <iostream>

using std::vector;
using std::pair;
using namespace std;


// O(n)
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

// O(log (n))
vector<pair<int, int>> mergeSort(vector<pair<int, int>> & numbers, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(numbers, middle + 1, right);
        mergeSort(numbers, left, middle);
        merge(numbers, left, middle, right);
    }
    return numbers;
}




vector<pair<int, int>> sortByDegree(vector<vector<int>> graph){
  vector<pair<int, int>> results;
  for(int i = 0; i < graph.size(); i++){
    int degree = 0;
    for(int j = 0; j < graph.size(); j++){
      degree += graph[i][j];
    }
    pair<int, int> newPair = {i, degree};
    results.push_back(newPair);
  }
  results = mergeSort(results, 0, results.size());
  return results;
}


void graphColoring(vector<vector<int>> graph){
  vector<pair<int, int>> degrees = sortByDegree(graph);
  vector<int> colors (graph.size(), -1);
  int currentLastColor = 1;

  for(int i = 0; i < graph.size(); i++){
    if(colors[degrees[i].first] == -1){
      colors[degrees[i].first] = currentLastColor;
      currentLastColor++;
      for(int j = 0; j < graph[degrees[i].first].size(); j++){
        if(colors[j] == -1 && graph[degrees[i].first][j] == 0){
          colors[j] = colors[degrees[i].first];
          cout << "nodo " << j+1 << " color de " << i+1 << endl;
        }
      }
    }
  }

  for(int k = 0; k < colors.size(); k++){
    cout << "Color del nodo " << k+1 << ": " <<colors[k] << endl;
  }
}