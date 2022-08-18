/*
Nombre: Actividad 1.0 - Complejidad Empirica.
Descripción: Actividad para generar intuación de la complejidad, 
                analizando un programa que suma m intancias de n números.
Autor: Jeshua Nava Avial | A01639282
Fecha de creación y modificación: 17/08/2022 - XX/08/2022
*/
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

int main (int argc, char *argv[]) {
    int n;
    int DATA[10];
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

    std::clock_t begin = clock();
    // Calculamos la suma
    for (int i = 0; i < n; i++){
        sum += DATA[i];
    }
    std::clock_t end = clock();
    double elapsed_secs = double(end - begin) /CLOCKS_PER_SEC;
    // Imprimimos los resultados
    std::cout << "La suma es: " << sum << std::endl;
    std::cout << "Tiempo en segundos: " << elapsed_secs << std::endl;
    return 0;
}