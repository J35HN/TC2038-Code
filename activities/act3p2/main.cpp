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
  vector<int> dijkstraResultMatrix = matrix[0];

  // insert values in matrix.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  // Compute results.
  dijkstraResultMatrix = dijkstraAlgorithm(matrix, 0);

  /*
  for (int i = 0; i < n; i++) {
    cout << std::endl;
    for (int j = 0; j < n; j++) {
      cout << " " << matrix[i][j];
    }
  }
  */

  return 0;
}