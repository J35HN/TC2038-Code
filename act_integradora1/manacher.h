#include <vector>
#include <string>

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
std::vector<int> manacher(std::vector<int>& indexArray, std::string str)
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