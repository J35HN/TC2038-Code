/*
Nombre: Actividad 3.4 - Implementación de "Graph Coloring".
Descripción: Programa que recibe una matriz de adyacencia y asigna un color a cada nodo
Autores: 
Jeshua Nava Avila | A01639282
Gael Rodriguez Gomez | A01639279
Fecha de creación y modificación: 17/10/2022 - 25/10/2022

Descripcion:
  Un programa que recibe un numero n y luego una matriz de adyacencia con n filas y columnas
  Despues, realiza un coloreado del grafo utilizando un algoritmo de Welsh-Powell

* Compilacion (Replit):
    g++ -std=c++17 -g -o main *.cpp
* Ejecucion (Replit):
    ./main < pruebaN.txt


  Grafo en prueba1.txt:

   B - E
  /   /
 A - D
  \ / \
   C   F
  Grafo en prueba2.txt:

  A - E
  |  /|
  | B |
  |/  |
  c - D

  Grafo en prueba3.txt:

 	  B - C
 	 /     \
 	A       F
   \     /
 	  D - E


  Grafo en prueba4.txt:
 ---A-------B---
 |  | \    /|  |
 |  |  \ /  |  |
 |  |  / \  |  |
 |  |/     \|  |
 | /|       |\ |
 F \|       |/ C
 |  |\     /|  |
 |  |  \ /  |  |
 |  |  / \  |  |
 |  |/     \|  |
 -- E ----- D --

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

  // Compute values
  graphColoring(graph);
  cout << "a";
}