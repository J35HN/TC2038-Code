/*
Nombre: Actividad 3.1 - Implementación de "Tries".
Descripción: Programa que implementa un Trie y verifica
                su funcionalidad con inserción y busqueda.
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 05/10/2022 - XX/10/2022
*/
#include <iostream>
#include <vector>

void readData (std::vector<std::string>& list, int n)
{
    std::string word;
    for (int i = 0; i < n; i++)
    {
        std::cin >> word;
        list.push_back(word);
    }
}

int main(int argc, char *argv[])
{
    int n = 0, m = 0;
    std::string word;
    std::vector<std::string> wordsInTrie;
    std::vector<std::string> wordsToSearch;
    // Read amount of words to insert.
    std::cin >> n;
    // Store n amount of words.
    readData(wordsInTrie, n);
    // Read amount of words to search.
    std::cin >> m;
    // Store m amount of words.
    readData(wordsToSearch, m);
    // Print results.
    for (int i = 0; i < n; i++)
    {
        std::cout << wordsInTrie[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m; i++)
    {
        std::cout << wordsToSearch[i] << " ";
    }
    return 0;
}