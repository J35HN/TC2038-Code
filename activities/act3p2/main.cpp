/*
Nombre: Actividad 3.2 - Implementación de "Dijkstra and Floyd".
Descripción: 
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 07/10/2022 - 14/10/2022
*/
#include <iostream>
#include <vector>

#include "dijkstra.h"
#include "floyd.h"

using std::cin;
using std::cout;
using std::vector;


int main(int argc, char *argv[]) {
  int n = 0;

  // Read values from txt file.
  cin >> n;
  // Init square matrix and result matrix.
  vector<vector<int>> matrix(n, vector<int>(n));
  vector<vector<int>> dijkstraResultMatrix = matrix;
  vector<int> dijkstraResultArray = matrix[0];
  vector<vector<int>> floydResultMatrix = matrix;

  // insert values in matrix.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  // Compute results.
  /// Dijkstra.
  /// For each node, compute its shortest path for the graph.
  for (int node = 0; node < matrix[0].size(); node++)
  {
    dijkstraResultArray = dijkstraAlgorithm(matrix, node); // Obtain the array of its shortest path.
    dijkstraResultMatrix[node] = dijkstraResultArray; // Insert the array into a matrix of results.
  }
  /// Floyd.
  floydResultMatrix = floydAllPairsAlgorithm(matrix);
  
  // Print results.
  /// Dijkstra.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j)
      {
        cout << "node " << i+1 << " to node " << j+1 << " : " << dijkstraResultMatrix[i][j];
        cout << std::endl;
      }
    }
  }
  /// Floyd.
  for (int i = 0; i < n; i++) {
    cout << std::endl;
    for (int j = 0; j < n; j++) {
      cout << " " << floydResultMatrix[i][j];
    }
  }
  return 0;
}