/*
    Name: Activity 3.1 - "Tries" implementation.
    Description: Program that implements a "Trie" data structure and
    verifies its correct functionality by allowing insertion and search for words.
    Autors: Jeshua Nava Avila | A01639282
            Luis David López Magaña | A00344656
    Date of creation: 05/10/2022 - 11/10/2022
*/

#include <bits/stdc++.h>
#include "trie.h"
#include "dfs.h"

/**
 * @brief Function that reads input words through the command line.
 * 
 * @param list Vector that stores the input.
 * @param n Number of words to input.
 * Complexity: O(n), where n is the number of words.
 */
void readData(std::vector<std::string> &list, int n)
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
    struct TrieNode *root = getEmptyNode();

    // Read amount of words to insert.
    std::cin >> n;
    // Store n amount of words.
    readData(wordsInTrie, n);
    // Read amount of words to search.
    std::cin >> m;
    // Store m amount of words.
    readData(wordsToSearch, m);
    // Insert n amount of words into our trie.
    for (int i = 0; i < n; i++)
    {
        insertNode(root, wordsInTrie[i]);
    }
    // Depth-first traversal of the trie.
    dfs(root, ' ');
    // Search our m amount of desired words.
    for (int i = 0; i < m; i++)
    {
        std::cout << searchWord(root, wordsToSearch[i]) << std::endl;
    }


    return 0;
}