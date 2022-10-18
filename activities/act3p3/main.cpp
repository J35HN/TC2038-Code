/*
Nombre: Actividad 3.3 - Implementación de "Knapsack problem".
Descripción: Programa que resuelva el problema de la mochila (Knapsack problem)
Autores: 
Jeshua Nava Avila | A01639282
Gael Rodriguez Gomez | A01639279
Fecha de creación y modificación: 15/10/2022 - 18/10/2022

* Compilacion (Replit):
    g++ -std=c++17 -g -o main *.cpp
* Ejecucion (Replit):
    ./main < pruebaN.txt

*/
#include <iostream>

#include "knapsack_Algorithm.h"

using std::cin;
using std::cout;
using std::vector;

int main(int argc, char *argv[])
{
    int N = 0, W = 0, value = 0;
    // Init vectors.
    vector<int> elementValues;
    vector<int> elementWeights;
    // Read values from txt file.
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> W;
        elementValues.push_back(W);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> W;
        elementWeights.push_back(W);
    }
    cin >> W;

    // Compute value
    value = KnapsackAlgorith(elementValues, elementWeights, W);
    cout << value;

    return 0;
}