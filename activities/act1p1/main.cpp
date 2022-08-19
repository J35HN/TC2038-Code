/*
Nombre: Actividad 1.1 - Implementación de la técnica de programacion "divide y vencerás"
Descripción: Actividad para poner en práctica la técnica de progrmación 
                "Divide y Vencerás".
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 18/08/2022 - XX/08/2022
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <string>
#include <cstdlib>

int main (int argc, char *argv[]) {
    std::vector<int> list;
    // Revisamos si vamos a obtener nuestra instancia de un txt o de inputs.
    if (argc > 2) {
        std::cout << "Inputs" << std::endl;
        for (int i = 1; i < argc; i++) {
            list.push_back(std::atoi(argv[i]));
        }
    } else {
        std::cout << "file" << std::endl;
    }
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    return 0;
}