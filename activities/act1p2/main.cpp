/*
Nombre: Actividad 1.2 -    
        Implementación de la técnica de programación 
        "Programación dinámica" y "algoritmos avaros"
Descripción: Actividad para generar práctica de "Programación Dinámica"
                y "Algoritmos Avaros".
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 23/08/2022 - XX/08/2022
*/
#include <iostream>
#include <vector>
#include <math.h>

/**
 * @brief Read coin data from txt file that has been passed as an argument.
 * 
 * @param validCoins List that will contain the value of the valid coins.
 * @param N Amount of valid coins.
 * Complexity: O(n).
 */
void readData (std::vector<int>& validCoins, int N)
{
    int data = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> data;
        validCoins.push_back(data);
    }
}

/**
 * @brief merge algorith from Merge Sort. Sorts from largest to smalles value.
 * 
 * @param list List that contains the data and that will be sorted with other two sub-vectors.
 * @param leftIndex Indicates the numeric value of the starting index of the list.
 * @param middleIndex Indicates the numeric value of the middle index of the list.
 * @param rightIndex Indicates the numeric value of the end or last possible index of the list.
 * Complexity: O(n).
 */
void merge (std::vector<int>& list, int leftIndex, int middleIndex, int rightIndex)
{
    std::vector<int> leftList, rightList; // Temporal sub-vectors. (STARTING WITH NO VALUE).
    int leftSize = 0, rightSize = 0, i = 0, j = 0;
    int trueIndex = leftIndex;
    // Calculte the "length" of the sub-vectors. They end up size + 1, to compensate
    //      for 0-indexing in cpp.
    leftSize = middleIndex - leftIndex + 1;
    rightSize = rightIndex - middleIndex;
    // Copy corresponding values of list to the sub-vectors.
    for (int i = 0; i < leftSize; i++)
    {
        leftList.push_back(list[leftIndex + i]);
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightList.push_back(list[middleIndex + j + 1]);
    }
    i = j = 0; // Reset indexes for independent use in left and right sub-vectors.
    // Compare and add numbers to our list.
    while (i < leftSize && j < rightSize)
    {
        if (leftList[i] >= rightList[j])
        {
            list[trueIndex] = leftList[i];
            i++;
        }
        else
        {
            list[trueIndex] = rightList[j];
            j++;
        }
        trueIndex++;
    }
    // If any elements are left in our sub-vectors, we add them to our list.
    while (j < rightSize)
    {
        list[trueIndex] = rightList[j];
        j++;
        trueIndex++;
    }
    while (i < leftSize)
    {
        list[trueIndex] = leftList[i];
        i++;
        trueIndex++;
    }
    
}

/**
 * @brief Merge Sort algorithm. Divides the list into sub-vectors, and sorts from largest to smallest.
 * 
 * @param list The list to sort. 
 * @param leftIndex The value of the starting index of the list.
 * @param rightIndex The value of the last index of the list.
 * Complexity: O(n log(n)).
 */
void mergeSort (std::vector<int>& list, int leftIndex, int rightIndex)
{
    int middleIndex = 0;
    // Verify if we need to create more sub-problems.
    if (leftIndex < rightIndex)
    {
        middleIndex = std::floor((leftIndex + rightIndex) / 2); 
        mergeSort(list, leftIndex, middleIndex);
        mergeSort(list, middleIndex + 1, rightIndex);

        merge(list, leftIndex, middleIndex, rightIndex);
    }
    
}

void fillWithCeroNAmount (std::vector<int>& vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector.push_back(0);
    }
}

void greedyAlgorithm (std::vector<int>& denominations, std::vector<int>& solution, int change)
{
    int currentCoin = 0, remainder = change;
    // Travel each denomination value and calculate amount needed of each.
    for (int i = 0; i < denominations.size(); i++)
    {
        currentCoin = denominations[i];
        // If we already have the exact change and still have coins in our denomination,
        // leave the amount 0. If not, calculate the amount needed of the current coin.
        if (remainder > 0)
        {
            if (remainder / currentCoin > 0)
            {
                solution[i] = remainder / currentCoin;
            }
            remainder %= currentCoin;
        }
    }
}

void dynamicAlgorithm (std::vector<int>& denominations, std::vector<int>& solution, int change)
{
    std::vector<int> coinsUsed;
    int temp = 0, j = 0, size = denominations.size();
    // Fill with 0s to be size of change.
    fillWithCeroNAmount(coinsUsed, change + 1);
    for (int i = 1; i <= change; i++)
    {
        temp = change + 1;
        j = 1;
        // We traverse our denominations vector from right to left.
        // So to size we subtract j.
        while (j <= denominations.size() && i >= denominations[size - j])
        {
            temp = std::min(coinsUsed[i - denominations[size - j]], temp);
            j += 1;
        }
        if (i % denominations[size - j + 1] == 0)
        {
            std::cout << denominations[size - j + 1] << std::endl;    
        }
        else
        {
            std::cout << denominations[size - j + 2] << std::endl;
        }
        //std::cout << denominations[size - j + 1] << std::endl;
        coinsUsed[i] = temp + 1;
    } 
    std::cout << "coins used: " << coinsUsed[change] << std::endl;
    for (int i = 0; i <= change; i++)
    {
        std::cout << coinsUsed[i] << " ";
    }
    std::cout << std::endl; 
}

int main (int argc, char *argv[])
{
    std::vector<int> denominationCoins;
    int N = 0, P = 0, Q = 0;
    std::vector<int> greedySolution;
    std::vector<int> dynamicSolution;
    // Read amount of arguments/valid coins inputs, and the values of the coins.
    std::cin >> N;
    readData(denominationCoins, N);
    // Fill with 0 our solution vectors.
    fillWithCeroNAmount(greedySolution, N);
    fillWithCeroNAmount(dynamicSolution, N);
    // Order from biggest to smallest our denommination list (just in case).
    mergeSort(denominationCoins, 0, denominationCoins.size() - 1);
    // Read product price and payment.
    std::cin >> P;
    std::cin >> Q;
    // Obtain solutions
    greedyAlgorithm(denominationCoins, greedySolution, Q - P);
    dynamicAlgorithm(denominationCoins, dynamicSolution, Q - P);
    // Present solutions.
    std::cout << "Amount of valid coins: " << N << std::endl;
    std::cout << "Product Price: " << P << ". Payment: " << Q << ". Change: " << Q - P << std::endl; 
    std::cout << "Coin denominations:" << std::endl << "{ ";
    for (int i = 0; i < N; i++)
    {
        std::cout << denominationCoins[i] << " ";
    }
    std::cout << "}" << std::endl << std::endl << "SOLUTIONS" << std::endl;
    std::cout << "Greedy Algorithm Solution" << std::endl << "{ ";
    for (int i = 0; i < N; i++)
    {
        std::cout << denominationCoins[i] << ":" << greedySolution[i] << " ";
    }
    std::cout << " }" << std::endl;
    std::cout << "Dynamic Algorithm Solution" << std::endl << "{ ";
    for (int i = 0; i < N; i++)
    {
        std::cout << denominationCoins[i] << ":" << dynamicSolution[i] << " ";
    }
    std::cout << " }";
    return 0;
}