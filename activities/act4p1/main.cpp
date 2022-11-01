/*
Nombre: Actividad 4.1 - Implementación Intersección y proximidad aplicando geometría computacional.
Descripción: Programa que determina si dos segementos de rectas intersectan utilizando un 
    algoritmo de Sweep Line.
Autores: 
Jeshua Nava Avila | A01639282
Gael Rodriguez Gomez | A01639279
Fecha de creación y modificación: 31/10/2022 - xx/11/2022
*/

#include "SweepLine.h"

int main (int argc, char *argv[])
{
    string l1, l2;
    vector<pair<int, int>> line1;
    vector<pair<int, int>> line2;
    // Read the coordinates sets.
    std::getline(cin, l1);
    std::getline(cin, l2);
    // Convert and store values.
    std::istringstream strm1(l1);
    std::istringstream strm2(l2);
    while(strm1 && strm2)
    {
        string s1, s2, s3, s4;
        // Grab each pair of coordinates.
        strm1 >> s1; 
        strm1 >> s2;
        strm2 >> s3;
        strm2 >> s4;
        // Check if we still have a valid stream (to avoid stoi invalid argument).
        if (strm1 && strm2){            
            // Convert to int.
            pair<int, int> coordinate1 = {std::stoi(s1), std::stoi(s2)};
            pair<int, int> coordinate2 = {std::stoi(s3), std::stoi(s4)};
            line1.push_back(coordinate1);
            line2.push_back(coordinate2);
        }
    }
    for (int i = 0; i < line1.size(); i++)
    {
        cout << line1[i].first << "," << line1[i].second << " ";
    }
    return 0;
}