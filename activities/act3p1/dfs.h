
/**
 * @brief Traverses the Trie and prints the node's value in 
 * Depth-First order.
 * 
 * @param root Root of the current subtree.
 * @param letter Character associated with the node.
 * Complexity: O(n), where n is the number of nodes.
 */
void dfs(TrieNode *root, char letter)
{
    TrieNode *tempNode = root; // Take reference.

    // Check every letter in the english alphabet.
    for (int i = 0; i < 26; i++) 
    {
        // If it has a node with this character, apply dfs again.
        if (tempNode->children[i])
        {
            dfs(tempNode->children[i], char(i + 'a'));
        }
    }

    std::cout << letter << std::endl;
}
