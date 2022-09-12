#include <iostream>
#include <vector>
#include <string.h>

std::vector<std::vector<int>> LCSMatrix (std::string s1, std::string s2)
{
    // Construct vector of s1 x s2
    std::vector<std::vector<int>> matriz(s1.size() + 1, std::vector<int> (s2.size() + 1, 0));

    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                matriz[i][j] = 0;
            }
            else if (s1[i] == s2[j])
            {
                matriz[i][j] = 1 + matriz[i-1][j-1];
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }

    return matriz;    
}

int main (int argc, char *argv[])
{
    std::string s1 = "ABCXYZAY";
    std::string s2 = "XYZABCB";
    std::vector<std::vector<int>> matriz;

    matriz = LCSMatrix (s1, s2);

    // Print values
    for (int i = 0; i < s1.size() + 1; i++)
    {
        for (int j = 0; j < s2.size() + 1; j++)
        {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}