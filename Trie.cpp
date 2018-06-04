#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord; // indicates if any word ends at this node
};

// A utility function that returns a new instance of the Trie node.
TrieNode *getNode() {
    auto *pNode = new TrieNode;
    pNode -> isEndOfWord = false;
    for(auto &child : pNode -> children)
        child = nullptr;

    return pNode;
}

// A utility function to insert a new string in Trie.
// if the path to a particular character not already exists, create a new node accordingly
// At the last node mark the node as end of word.
void insert(TrieNode *root, string key) {
    TrieNode *p_crawl = root;

    // for every character in the string, traverse to the correct node
    for(auto ch : key) {
        int index = ch - 'a';
        if(!p_crawl -> children[index]) // if no such node exists then create one
            p_crawl -> children[index] = getNode();
        p_crawl = p_crawl -> children[index];
    }

    // mark leaf as the end of node
    p_crawl -> isEndOfWord = true;
}

// A utility that searches for the occurrence of a string in the trie, returns true if found, false otherwise.
bool search(TrieNode *root, string str) {
    struct TrieNode *p_crawl = root;

    for(auto ch : str) {
        int index = ch - 'a';
        if(!p_crawl -> children[index])
            return false;
        p_crawl = p_crawl -> children[index];
    }

    return (p_crawl != nullptr and p_crawl -> isEndOfWord);
}


int main() {
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    // create an instance of TrieNode - root
    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    cout << (search(root, "the") ? "\"the\" exists in the trie" : "\"the\" does not exist in the trie") << endl;
    cout << (search(root, "these") ? "\"these\" exists in the trie" : "\"these\" does not exist in the trie");

    return 0;
}
