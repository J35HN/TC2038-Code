/*
Nombre: Actividad 1.2 -    
        Implementación de la técnica de programación 
        "Programación dinámica" y "algoritmos avaros"
Descripción: Actividad para generar práctica de "Programación Dinámica"
                y "Algoritmos Avaros".
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 23/08/2022 - 30/08/2022
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

/**
 * @brief Fills a vector with values of ceros, for n times.
 * 
 * @param vector The vector to fill with ceros.
 * @param n The amount of ceros.
 * Complexity: O(n).
 */
void fillWithCeroNAmount (std::vector<int>& vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector.push_back(0);
    }
}

/**
 * @brief Greedy Algorithm for the coin change problem.
 * 
 * @param denominations Vector that contains the coins denominations.
 * @param solution Vector that will contain the solutions.
 * @param change The change to add up with our coin denominations.
 * Complexity: O(n).
 */
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

/**
 * @brief Dynamic Programming Algorithm for the coin change problem.
 * 
 * @param denominations Vector that contains the coins denominations.
 * @param solution Vector that will contain the solutions.
 * @param change The change to add up with our coin denominations.
 * Complexity: O(n*m).
 * Worst case Complexity: O(n^2). If the amount of coin denominations is equal to our change, complexity 
 *  will grow due to having a while in a for loop. Complexity could be better, if DP was implemented
 * in a tree with recursion, and not a For Loop.
 */
void dynamicAlgorithm (std::vector<int>& denominations, std::vector<int>& solution, int change)
{
    std::vector<int> coinsUsed;
    std::vector<int> lastCoinUsed;
    int temp = 0, j = 0, index = 0, remainder = 0, size = denominations.size();
    // Fill with 0s to be size of change.
    fillWithCeroNAmount(coinsUsed, change + 1);
    fillWithCeroNAmount(lastCoinUsed, change + 1);
    // Dynammicly obtain the amount of coins used.
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
        j -= 1;
        // Calculate the last coin used.
        // Traverse each denomination used until i % CurrentDenomination == 0.
        // After, add it to our other vector.
        remainder = i;
        while (j >= 1)
        {
            if (i % denominations[size - j] == 0)
            {
                lastCoinUsed[i] = denominations[size - j];
                j = 0;
            }
            else
            {
                remainder %= denominations[size - j];
                j -= 1;
            }
        }
        coinsUsed[i] = temp + 1;
    }
    // With the vector lastCoinUsed, we can obtain the values of the coins used.
    // Just traverse the vector, from the last value, subtracting each value to the index.
    while (change > 0)
    {
        temp = lastCoinUsed[change];
        // Search for corresponding index in denominations, to add one to our solution in index.
        for (int i = 0; i < denominations.size(); i++)
        {
            if (temp == denominations[i])
            {
                index = i;
            }
        }
        solution[index] = solution[index] + 1;
        change -= temp;
    }
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
    for (int i = 0; i < N; i++)
    {
        std::cout << dynamicSolution[i] << std::endl;
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << greedySolution[i] << std::endl;
    }
    return 0;
}