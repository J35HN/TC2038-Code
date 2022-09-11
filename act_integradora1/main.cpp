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

int openFileAndStoreInVar (std::string& str, std::string path)
{
    std::ifstream inFile;
    inFile.open(path);
        if (inFile.is_open())
        {
            std::stringstream strStream;
            strStream << inFile.rdbuf();
            str = strStream.str();
            return 1;
        }
        else
        {
            std::cout << "Could not open file: " << path << std::endl;
            return 0;
        }
}

int main (int argc, char *argv[])
{
    std::string transmision1 = "";
    std::string transmision2 = "";
    std::string mcode1 = "";
    std::string mcode2 = "";
    std::string mcode3 = "";
        
    // Store the file content into the strings.
    int openSuccess = openFileAndStoreInVar(transmision1, "transmission1.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(transmision2, "transmission2.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(mcode1, "mcode1.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(mcode2, "mcode2.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(mcode3, "mcode3.txt"); if(openSuccess == 0){return 0;}
    
    return 0;
}