/*
Nombre: Actividad 3.3 - Implementación de "Knapsack problem".
Descripción: Programa que resuelva el problema de la mochila (Knapsack problem)
Autores: 
Jeshua Nava Avila | A01639282
Gael Rodriguez Gomez | A01639279
Fecha de creación y modificación: 15/10/2022 - XX/10/2022
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main(int argc, char *argv[])
{
    int N = 0, W = 0;
    // Init vectors.
    vector<int> valuesOfElements;
    vector<int> weightsOfElements;
    // Read values from txt file.
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> W;
        valuesOfElements.push_back(W);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> W;
        weightsOfElements.push_back(W);
    }
    cin >> W;

    // Print values.
    cout << "N : " << N << std::endl;
    cout << "W : " << W << std::endl;
    cout << "Values of elements: ";
    for (int i = 0; i < N; i++)
    {
        cout << valuesOfElements[i] << " ";
    }
    cout << std::endl << "Values of weights: ";
    for (int i = 0; i < N; i++)
    {
        cout << weightsOfElements[i] << " ";
    }

    return 0;
}