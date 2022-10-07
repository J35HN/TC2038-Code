#include <bits/stdc++.h>

// Define a node of a 'trie' (characteristics).
struct TrieNode
{
    struct TrieNode *children[26]; // Each node can have up to 26 unique (english) letters connected.
    bool wordEndsHere; // Indicates if a node is the end of a word.
};

// Funciton to obtain an empty node.
struct TrieNode *getEmptyNode(void)
{
    struct TrieNode *emptyNode = new TrieNode; // Creates a trie node.
    emptyNode -> wordEndsHere = false; // Define that it is not part of a word (still).
    // Have each children be NULL, due to it being a blank trie node.
    for (int i = 0; i < 26; i++)
    {
        emptyNode -> children[i] = NULL;
    }
    return emptyNode;
}

// Function to insert a node in a trie.
void insertNode (struct TrieNode *root, std::string str)
{
    struct TrieNode *tempNode = root; // Take reference.
    // Add each character to its proper place.
    int strLength = str.length();
    for (int i = 0; i < strLength; i++)
    {
        int letterIndex = str[i] - 'a'; // Obtains the index of the str[i] character in the english alphabet (a = 0, b = 1...).
        // If a character is not at the index, create a new node.
        if (!tempNode -> children[letterIndex])
        {
            tempNode -> children[letterIndex] = getEmptyNode();
        }
        tempNode = tempNode -> children[letterIndex]; // Move to node at letterIndex;
    }
    tempNode -> wordEndsHere = true; // Mark last node as the end of a word.
}

// Function to search a word in a trie.
bool searchWord (struct TrieNode *root, std::string str)
{
    struct TrieNode *tempNode = root; // Take reference.
    // Iterate over each character.
    int strLength = str.length();
    for (int i = 0; i < strLength; i++)
    {
        int letterIndex = str[i] - 'a'; // Obtain the character's index.
        // If NULL appears at the index, return false (character is not there).
        // If not, avance to the character's existing node.
        if (tempNode -> children[letterIndex] == NULL)
        {
            return false;
        }
        tempNode = tempNode -> children[letterIndex];
    }
    // If we are at the last character in the string, and it's 'wordEndsHere', return it's value.
    // Also double check that the current node is not NULL.
    return (tempNode -> wordEndsHere && tempNode != NULL);
}