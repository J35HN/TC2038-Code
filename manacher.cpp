#include <iostream>
#include <string.h>
#include <vector>

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
    std::string str = "abacabacabb";
    std::string longestPalindrome = "";
    std::vector<int> indexArray(str.size() * 2, 0);
    longestPalindrome = longestPalindromeSubStr(indexArray, str);
    std::cout << "\n" << longestPalindrome;
    return 0;
}