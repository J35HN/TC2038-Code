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

const int MAX = 50000;

void readData(int list[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
}

int main (int argc, char *argv[]) {
    int list[MAX];
    int number = 0;
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