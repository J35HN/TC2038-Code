#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Generates the prefix table for a given pattern.
 * 
 * @param pattern String from which the table will be created
 * @param sizePattern Size of the string.
 * @return A vector that contains the sizes of the longest proper
 * prefixes that are also a suffix in the substrings spanning
 * from index 0 to any index.
 * 
 * Complexity: O(n).
 */
std::vector<int> generateLPS(std::string pattern, int sizePattern) {
    std::vector<int> lps(sizePattern + 1);

    int index = 1, currentLongestPrefix = 0;

    while (index < sizePattern) {
        if (pattern[index] == pattern[currentLongestPrefix]) {
            currentLongestPrefix++;
            lps[index + 1] = currentLongestPrefix;
            index++;
        } else if (currentLongestPrefix == 0) {
            lps[index + 1] = 0;
            index++;
        } else {
            currentLongestPrefix = lps[currentLongestPrefix];
        }
    }   

    return lps;
}

/**
 * @brief Determines if a given pattern can be found within another
 * string.
 * 
 * @param mainString String where the pattern will be searched.
 * @param sizePattern String to search for in the main string.
 * @return a boolean representing whether or not it was found.
 * 
 * Complexity: O(n).
 */
bool kmp(std::string mainString, std::string pattern) {
    std::vector<int> lps = generateLPS(pattern, pattern.size());

    pattern = " " + pattern;


    int i = 0, j = 0;

    while (i < mainString.size()) {
        if (mainString[i] == pattern[j + 1]) {
            i++;
            j++;
        } else if (j > 0) {
            j = lps[j];
        } else {
            i++;
        }

        if (j == pattern.size() - 1) {
            return true;
        }
    }

    return false;

}