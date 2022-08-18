/*
Nombre: Actividad 1.0 - Complejidad Empirica.
Descripción: Actividad para generar intuación de la complejidad, 
                analizando un programa que suma m intancias de n números.
Autor: Jeshua Nava Avial | A01639282
Fecha de creación y modificación: 17/08/2022 - 18/08/2022
*/
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

int main (int argc, char *argv[]) {
    int n;
    int DATA[50000];
    int sum = 0;
    int number;
    std::string fn = std::string(argv[1]); // nombre del archivo.
    std::ifstream input_file(fn);
    
    if (!input_file.is_open()) {
        std::cerr << "No fue posible abrir el archivo - '"
            << fn << "'" << std::endl;
        return EXIT_FAILURE;
    }
    int i = 0;
    while (input_file >> number) {
        DATA[i] = number;
        i++;
    }
    input_file.close();
    n = i;

    auto begin = std::chrono::steady_clock::now();
    // Calculamos la suma
    for (int i = 0; i < n; i++){
        sum += DATA[i];
    }
    auto end = std::chrono::steady_clock::now();
    double elapsed_secs = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    // Imprimimos los resultados
    std::cout << "La suma es: " << sum << std::endl;
    std::cout << "Tiempo en microseconds: " << elapsed_secs << std::endl;
    return 0;
}