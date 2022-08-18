#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[])
{
    int numbersToGenerate = stoi(std::string(argv[1]));
    int rangeOfRandomNumbers = stoi(std::string(argv[2]));
    int n = 0;
    
    std::string nameOfFile = std::to_string(numbersToGenerate) + "randomNumbers.txt";
    // Create and open text file
    std::ofstream MyFile(nameOfFile);
    // Write to file
    for (int i = 0; i < numbersToGenerate; i++)
    {
        if (i == numbersToGenerate -1)
        {
            n = rand()%rangeOfRandomNumbers;
            MyFile << n;    
        } 
        else 
        {
            n = rand()%rangeOfRandomNumbers;
            MyFile << n << "\n";
        }
    }
    // Close file
    MyFile.close();

    return 0;
}