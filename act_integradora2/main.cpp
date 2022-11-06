/*
Nombre: Actividad Integradora 2.
Descripción: 
- Programa en CPP que ayuda una empresa que quiere incursionar en los servicios de Internet 
    respondiendo a la situación problema 2, con algoritmos de gráfos.
Autores:
- Jeshua Nava Avila | A01639282
- Gael Rodriguez Gomez | A01639279
Fecha de creación y última modificación: 
- 06/11/2022 - 18/11/2022

* Compilar
    g++ -std=c++17 main.cpp
* Ejecutar en Linux
    ./a.out < filename
* Ejecutar en Windows CMD
    a.exe < filename

*/

#include <bits/stdc++.h>

#include "Location.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;
using std::stoi;

/**
 * @brief Read values (with cin) of a file, that are in a
 * order of n x n, and insert the values in a matrix.
 * 
 * @param n Size of rows and columns of the input.
 * @param matrix Matrix where to store the values.
 * Complexity: O(n).
 */
void readInputForMatrix(int n, vector<vector<int>>& matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Read values (with cin) of a file, that are in a order
 * n of lines, and insert the values in a vector. Function specific
 * for reading the values of Locations: (x,y).
 * 
 * @param n Number of lines.
 * @param vector Vector where to store the values.
 * Complexity: O(ni), where i is the input size of the line read in cin.
 */
void readInputForVector(int n, vector<Location>& vector)
{
    string inputLine = "";
    string number = "";
    bool startOfNumber = false;
    bool firstCoordinate = true;
    Location location;
    unordered_map<string, int> validStrings = {
        {"1", 1}, {"2", 1}, {"3", 1}, {"4", 1}, {"5", 1}, 
        {"6", 1}, {"7", 1}, {"8", 1}, {"9", 1}, {"0", 1},
        {"(", 0}, {")", 0}
    };
    // Read and appropiate input for storing in locations vector.
    for (int i = 0; i < n; i++)
    {
        
        cin >> inputLine;
        // Traverse string and extract numbers.
        for (int p = 1; p < inputLine.size(); p++)
        {
            if(validStrings[string(1, inputLine[p])] == 1 && startOfNumber == false)
            {
                number += string(1, inputLine[p]);
                startOfNumber = true;
            } else if (validStrings[string(1, inputLine[p])] == 1 && startOfNumber == true)
            {
                number += string(1, inputLine[p]);
            } else if (validStrings[string(1, inputLine[p])] == 0 && startOfNumber == true)
            {
                if(firstCoordinate)
                {
                    location.x = stoi(number);
                    firstCoordinate = false;
                } else 
                {
                    location.y = stoi(number);
                    firstCoordinate = true;
                }
                number = "";
                startOfNumber = false;
            }
        }
        vector[i] = location;
        location.x = 0;
        location.y = 0;
    }
}

int main (int argc, char *argv[])
{
    int n = 0;
    
    // Read value of n.
    cin >> n;
    // Init. vectors.
    vector<vector<int>> distancesMatrix(n, vector<int>(n));
    vector<vector<int>> maxFluxMatrix(n, vector<int>(n));
    vector<Location> locations(n);
    // Store values in matrix of distances and maximum flux.
    readInputForMatrix(n, distancesMatrix);
    readInputForMatrix(n, maxFluxMatrix);
    // Store values of locations.
    readInputForVector(n, locations);
    // print values
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << distancesMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << maxFluxMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "(" << locations[i].x << "," << locations[i].y << ")" << endl;
    }
    return 0;
}