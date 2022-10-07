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