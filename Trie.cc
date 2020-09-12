#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

#define ALPHABET_SIZE 26

// Trie node
struct TrieNode
{
     struct TrieNode *children[ALPHABET_SIZE];
     // isEndOfWord is true if the node
     // represents end of a word
     bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
	pNode->isEndOfWord = false; 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 
	return pNode; 
} 

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
		root = getNode();
    }

	~Trie() {
		free(root);
	}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		struct TrieNode* node = root;
		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';
			if (node->children[index] == NULL)
			{
				node->children[index] = getNode();
			}
				
			node = node->children[index];
		}
		node->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		struct TrieNode* node = root;
		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';
			if (node->children[index] != NULL) 
			{
				node = node->children[index];
			} else {
				return false;
			}

		}
		if (node->isEndOfWord == true)
			return true;
		else
			return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		struct TrieNode* node = root;
		for (int i = 0; i < prefix.length(); i++) 
		{
			int index = prefix[i] - 'a';
			if (node->children[index] != NULL) 
				node = node->children[index];
			else 
				return false;
		}

		return true;
        
    }

private:
	struct TrieNode* root;
};

int main(){

	Trie* trie = new Trie();

	trie->insert("apple");
	cout << "==============" << endl;
	cout << trie->search("apple") << endl;   // returns true
	cout << "==============" << endl;
	cout << trie->search("a") << endl;     // returns false
	cout << "==============" << endl;

	cout << trie->startsWith("app") << endl; // returns true
	cout << "==============" << endl;

	trie->insert("app");   
	cout << trie->search("app") << endl;     // returns true
	return 0;

}
