/*
Nombre: Actividad Integradora 1.
Descripción: Primera actividad integradora, involucrando 
                algoritmos de busqueda de strings.
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 10/09/2022 - XX/09/2022
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>

/**
 * @brief Store the contents of a file into a string.
 * 
 * @param str String which will have the values of a file.
 * @param path The path of the file to open.
 * @return int Determines if the file was successfully open or not.
 * Complexity: O(1).
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

std::string convertString (std::string str)
{
    std::string newStr = "@";
    for (int i = 0; i < str.size(); i++)
    {
        newStr += "#" + str.substr(i, 1);
    }

    newStr += "#$";
    return newStr;
}

std::string longestPalindromeSubStr(std::vector<int>& indexArray, std::string str)
{
    std::string newStr = convertString(str);
    int center = 0, right = 0;
    for (int i = 1; i < newStr.size() - 1; i++)
    {
        int iMirror = center - (i - center);

        if (right > i)
        {
            indexArray[i] = std::min(right - i, indexArray[iMirror]);
        }

        while (newStr[i + 1 + indexArray[i]] == newStr[i - 1 - indexArray[i]])
        {
            indexArray[i] = indexArray[i] + 1;
        }

        if (i + indexArray[i] > right)
        {
            center = i;
            right = i + indexArray[i];
        }
    }

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < newStr.size() - 1; i++)
    {
        if (indexArray[i] > maxPalindrome)
        {
            maxPalindrome = indexArray[i];
            centerIndex = i;
        }
    }
    std::cout << maxPalindrome << " " << newStr[centerIndex] << std::endl;
    return str.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main (int argc, char *argv[])
{
    bool mcodeInTransmission = false;
    int startPos = -1, finalPos = -1;
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