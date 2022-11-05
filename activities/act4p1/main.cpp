/*
Nombre: Actividad 4.1 - Implementación Intersección y proximidad aplicando geometría computacional. 
Descripción: 
- Programa que determina cuales n segementos de rectas intersectan utilizando un algoritmo de Sweep Line.
Autores:
- Jeshua Nava Avila | A01639282
- Gael Rodriguez Gomez | A01639279
Fecha de creación y última modificación: 
- 31/10/2022 - 04/11/2022

* Compilar
    g++ -std=c++17 main.cpp
* Ejecutar en Linux
    ./a.out < filename
* Ejecutar en Windows CMD
    a.exe < filename

*/

#include "SweepLine.h"

int main(int argc, char *argv[]) {
  vector<Line> lines;
  int x0, y0, x1, y1, n;
  // Read amount of lines (segments).
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x0;
    cin >> y0;
    cin >> x1;
    cin >> y1;
    // Give a quick order (not a real sort).
    if (y0 >= y1) {
      lines.push_back(Line(Point(x0, y0), Point(x1, y1)));
    } else {
      lines.push_back(Line(Point(x1, y1), Point(x0, y0)));
    }
  }

  cout << "Hay " << sweepLine(lines) << " intersecciones" << endl;
  return 0;
}