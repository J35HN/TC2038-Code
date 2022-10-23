/*
Nombre: Actividad 3.4 - Implementación de "Graph Coloring".
Descripción: Programa que recibe una matriz de adyacencia y asigna un color a cada nodo
Autores: 
Jeshua Nava Avila | A01639282
Gael Rodriguez Gomez | A01639279
Fecha de creación y modificación: 17/10/2022 - 21/10/2022

* Compilacion (Replit):
    g++ -std=c++17 -g -o main *.cpp
* Ejecucion (Replit):
    ./main < pruebaN.txt
*/

#include <iostream>
#include "graphColoring.h"

using std::cin;
using std::cout;
using std::vector;

int main() {
  int n = 0;

  // Read values from txt file.
  cin >> n;
  // Init square matrix
  vector<vector<int>> graph(n, vector<int>(n));

  // insert values in matrix.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  graphColoring(graph);

}