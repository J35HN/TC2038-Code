#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
    std::string hexadecimalChars[17] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", 
        "A", "B", "C", "D", "E", "F", "\n"};
    std::string outputFileName = std::string(argv[1]);
    int charsToGenerate = stoi(std::string(argv[2]));

    // Initialize random seed.
    std::srand (time(NULL));

    // Create and open text file.
    std::ofstream MyFile(outputFileName);
    // Generate random chars.
    for (int i = 0; i < charsToGenerate; i++)
    {
        MyFile << hexadecimalChars[rand()%17];
    }
    // Close file.
    MyFile.close();
    return 0;
}