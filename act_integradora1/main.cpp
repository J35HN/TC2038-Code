/*
Nombre: Actividad Integradora 1.
Descripción: Primera actividad integradora, involucrando 
                algoritmos de busqueda de strings.
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 10/09/2022 - 30/09/2022
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>

int main (int argc, char *argv[])
{
    std::string transmision1 = "";
    std::string transmision2 = "";
    std::string mcode1 = "";
    std::string mcode2 = "";
    std::string mcode3 = "";
    std::string files[5] = {transmision1, transmision2, mcode1, mcode2, mcode3};
    std::string filesPath[5] = {"tranmision1.txt", "transmision2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};
    
    // Store the file content into the strings.
    std::ifstream inFile;
    inFile.open("mcode1.txt");
    if (inFile.is_open()){
        std::stringstream strStream;
        strStream << inFile.rdbuf();
        mcode1 = strStream.str();
        std::cout << mcode1;
    }
    else
    {
        std::cout << "Did not open" << std::endl;
    }
    

    
    return 0;
}