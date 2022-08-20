/*
Nombre: Actividad 1.1 - Implementación de la técnica de programacion "divide y vencerás"
Descripción: Actividad para poner en práctica la técnica de progrmación 
                "Divide y Vencerás".
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 18/08/2022 - XX/08/2022
*/
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>

const int MAX = 50000;

/**
 * @brief Read data from a txt file that has been passed as an argument.
 * 
 * @param list The list that will contain the inputs or data from the txt file.
 * @param n Amount of data to store in the list.
 * Complexity: O(n).
 */
void readData(int list[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
}

int main (int argc, char *argv[]) {
    int list[MAX];
    int n = 0;
    // Read amount of arguments/inputs.
    std::cin >> n;
    readData(list, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << list[i] << " ";
    }

    return 0;
}