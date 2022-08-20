/*
Nombre: Actividad 1.1 - Implementación de la técnica de programacion "divide y vencerás"
Descripción: Actividad para poner en práctica la técnica de progrmación 
                "Divide y Vencerás".
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 18/08/2022 - XX/08/2022
*/
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>

/**
 * @brief Read data from a txt file that has been passed as an argument.
 * 
 * @param list The list that will contain the inputs or data from the txt file.
 * @param n Amount of data to store in the list.
 * Complexity: O(n).
 */
 void readData (std::vector<int>& list, int n)
{
    int data = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> data;
        list.push_back(data);
    }
}

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
        if (leftList[i] <= rightList[j])
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
    while (i < leftSize)
    {
        list[trueIndex] = leftList[i];
        i++;
        trueIndex++;
    }
    while (j < rightSize)
    {
        list[trueIndex] = rightList[j];
        j++;
        trueIndex++;
    }
}

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

int main (int argc, char *argv[]) {
    std::vector<int> list;
    int n = 0;
    // Read amount of arguments/inputs.
    std::cin >> n;
    readData(list, n);
    mergeSort(list, 0, list.size() - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << list[i] << " ";
    }

    return 0;
}