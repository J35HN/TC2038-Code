/*
Nombre: Actividad Integradora 1.
Descripción: Primera actividad integradora, involucrando 
                algoritmos de busqueda de strings.
Autores: 
- Luis David Lopez Magaña | A00344656
- Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 10/09/2022 - 13/09/2022
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>

#include "lcs.h"
#include "kmp.h"
#include "manacher.h"

/**
 * @brief Stores the contents of a file into a string.
 * 
 * @param str String which will have the values of a file.
 * @param path The path of the file to open.
 * @return int Determines if the file was successfully open or not.
 * Complexity: O(n).
 */
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
    bool mcodeInTransmission = false;
    int startPos = -1, finalPos = -1;
    std::string transmision1 = "", transmision2 = "", mcode1 = "", mcode2 = "", mcode3 = "";
    std::vector<int> palindromeInfo(2, 0);
        
    // Store the file content into the strings.
    int openSuccess = openFileAndStoreInVar(transmision1, "transmission1.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(transmision2, "transmission2.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(mcode1, "mcode1.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(mcode2, "mcode2.txt"); if(openSuccess == 0){return 0;}
    openSuccess = openFileAndStoreInVar(mcode3, "mcode3.txt"); if(openSuccess == 0){return 0;}

    // Subtring in string.
    std::vector<std::string> transmissions{transmision1, transmision2};
    std::vector<std::string> mcodes{mcode1, mcode2, mcode3};

    for (int i = 0; i < transmissions.size(); i++) {
        for (int j = 0; j < mcodes.size(); j++) {
            std::string contains = kmp(transmissions[i], mcodes[j]) ? "true" : "false";
            std::cout << contains << std::endl;  
        }
    }

    // Longest Palindrome.
    // Transmission 1.
    std::vector<int> indexArray1(transmision1.size() * 2, 0);
    palindromeInfo = manacher(indexArray1, transmision1);
    std::cout << palindromeInfo[0] << " " << palindromeInfo[0] + palindromeInfo[1] - 1 << std::endl;
    // Transmission 2.
    std::vector<int> indexArray2(transmision2.size() * 2, 0);
    palindromeInfo = manacher(indexArray2, transmision2);
    std::cout << palindromeInfo[0] << " " << palindromeInfo[0] + palindromeInfo[1] - 1 << std::endl;
    // Longest Common Substring.
    lcs(transmision1, transmision2);
    return 0;
}