/*
Nombre: Actividad 4.2 - Implementación Polígonos Convexos aplicando geometría
computacional. Descripción:
- programa en C++ que implementa el algoritmo para determinar el polígono
convexo más pequeño en un conjunto de puntos aplicando el algoritmo de
Graham's Scan.

Autores:
- Jeshua Nava Avila | A01639282
- Gael Rodriguez Gomez | A01639279

\Fecha de creación y última modificación:
- 05/11/2022 - 08/11/2022

* Compilar
    g++ -std=c++17 main.cpp
* Ejecutar en Linux
    ./a.out < filename
* Ejecutar en Windows CMD
    a.exe < filename

*/

#include "Graham_Scan.h"

int main(int argc, char *argv[]) {
  int n = 0, x = 0, y = 0;
  vector<Point> points;
  // read input.
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cin >> y;
    points.push_back(Point(x, y));
  }
  // Compute.
  grahamScan(points);
  return 0;
}