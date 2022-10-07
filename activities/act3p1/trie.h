#include <bits/stdc++.h>

// Define a node of a 'trie'.
struct TrieNode
{
    struct TrieNode *children[26]; // Each node can have up to 26 unique (english) letters connected.
    bool wordEndsHere; // Indicates if a node is the end of a word.
};