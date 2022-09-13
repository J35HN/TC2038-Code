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

/**
 * @brief Inserts special characters to a string, for the use in Manacher Algorithm.
 * 
 * @param str String in which we insert the special characters.
 * @return string New string with special characters.
 * Complexity: O(n).
 */
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

/**
 * @brief Manacher algorithm for longest palindrome substring.
 * 
 * @param indexArray Array for index palindrome values.
 * @param str String from where we find a palindrome.
 * @return vector<int> Vector with the index position of the palindrom and its lenght.
 * Complexity: O(n).
 */
std::vector<int> longestPalindromeSubStr(std::vector<int>& indexArray, std::string str)
{
    std::string newStr = convertString(str);
    std::vector<int> palindromeInfo(2, 0);
    int center = 0, right = 0;
    int maxPalindrome = 0, centerIndex = 0;
    for (int i = 1; i < newStr.size() - 1; i++)
    {
        // Update mirror index.
        int iMirror = center - (i - center);

        if (right > i)
        {
            indexArray[i] = std::min(right - i, indexArray[iMirror]);
        }

        while (newStr[i + 1 + indexArray[i]] == newStr[i - 1 - indexArray[i]])
        {
            indexArray[i] = indexArray[i] + 1;
        }
        // Update center and right index.
        if (i + indexArray[i] > right)
        {
            center = i;
            right = i + indexArray[i];
        }
    }

    // Find the longest palindrome index value.
    for (int i = 1; i < newStr.size() - 1; i++)
    {
        if (indexArray[i] > maxPalindrome)
        {
            maxPalindrome = indexArray[i];
            centerIndex = i;
        }
    }
    // Store values of index and length.
    palindromeInfo[0] = (centerIndex - 1 - maxPalindrome) / 2; // Adjust to offset.
    palindromeInfo[1] = maxPalindrome;
    //str.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
    return palindromeInfo;
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
    palindromeInfo = longestPalindromeSubStr(indexArray1, transmision1);
    std::cout << palindromeInfo[0] << " " << palindromeInfo[0] + palindromeInfo[1] - 1 << std::endl;
    // Transmission 2.
    std::vector<int> indexArray2(transmision2.size() * 2, 0);
    palindromeInfo = longestPalindromeSubStr(indexArray2, transmision2);
    std::cout << palindromeInfo[0] << " " << palindromeInfo[0] + palindromeInfo[1] - 1 << std::endl;

    // Longest Common Substring.
    lcs(transmision1, transmision2);
    return 0;
}