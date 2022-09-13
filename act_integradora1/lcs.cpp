#include <iostream>
#include <string>
#include <vector>

void lcs(std::string str1, std::string str2) {

    std::vector<std::vector<long>> dp;
    long max = 0;
    long commonChars = 0;
    long startPosition1, endPosition1;
    long startPosition2, endPosition2;

    for (long i = 0; i < str1.size() + 1; i++) {
        dp.push_back(std::vector<long>(str1.size() + 1, 0));
        for (long j = 0; j < str2.size() + 1; j++) {
            if (i > 0 && j > 0) {
                if (str1[i - 1] == str2[j - 1]) {
                    commonChars = dp[i - 1][j - 1] + 1;
                    dp[i][j] = commonChars;

                    if (commonChars > max) {
                        max = commonChars;
                        startPosition1 = i - max;
                        startPosition2 = j - max;
                        endPosition1 = i - 1;
                        endPosition2 = j - 1;
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    std::cout << "Max substring length: " << max << std::endl;
    std::cout << "String 1: " << startPosition1 << " - " << endPosition1 << std::endl;
    std::cout << "String 2: " << startPosition2 << " - " << endPosition2 << std::endl;
}
 