#include <iostream>
#include <string>
#include <vector>

std::vector<int> generateLPS(std::string pattern, int sizePattern) {
    // int *lps = new int[sizePattern + 1];
    std::vector<int> lps(sizePattern + 1);

    int index = 1, currentLongestPrefix = 0;

    // aacaaaac
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

bool kmp(std::string transmission, std::string mcode) {
    std::vector<int> lps = generateLPS(mcode, mcode.size());

    mcode = " " + mcode;


    int i = 0, j = 0;

    while (i < transmission.size()) {
        if (transmission[i] == mcode[j + 1]) {
            i++;
            j++;
        } else if (j > 0) {
            j = lps[j];
        } else {
            i++;
        }

        if (j == mcode.size() - 1) {
            return true;
        }
    }

    return false;

}