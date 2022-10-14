/*
Nombre: Actividad 3.2 - Implementación de "Dijkstra and Floyd".
Descripción: 
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 07/10/2022 - XX/10/2022
*/
#include <iostream>
#include <vector>

#include "dijkstra.h"

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

  // insert values in matrix.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  // Compute results.
  /// Dijkstra.
  for (int node = 0; node < matrix[0].size(); node++)
  {
    dijkstraResultArray = dijkstraAlgorithm(matrix, node);
    dijkstraResultMatrix[node] = dijkstraResultArray;
  }
  
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

  return 0;
}