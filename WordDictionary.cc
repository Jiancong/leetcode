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

class WordDictionary { 
public:

	struct TrieNode* searchUtil(string word, struct TrieNode* rootF) {
		struct TrieNode* node = rootF;
		for (int i = 0; i < word.length(); i++) 
		{
			if (word[i] == '.') {
				string newword = word.substr(i+1);
				struct TrieNode* foundNode = NULL;
				for (int j = 0; j < ALPHABET_SIZE; j++)
				{
					struct TrieNode* newroot = node->children[j];
					if (!newroot) continue;

					foundNode = searchUtil(newword, newroot);
					if (foundNode && foundNode->isEndOfWord) return foundNode;
				}

				return foundNode;
			} else {
				int index = word[i] - 'a';
				if (node->children[index] != NULL) 
					node = node->children[index];
				else 
					return NULL;
			}
		}
		return node;
	}

	/** Initialize your data structure here. */
    WordDictionary() {
		root = getNode();		
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {

		struct TrieNode* node = searchUtil(word, root);
		if (node && node->isEndOfWord)
			return true;
		else 
			return false;
        
    }
private:
	struct TrieNode* root;
};

int main(){

	WordDictionary wd;
	/*
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	cout << wd.search("pad") << endl;
	cout << wd.search("bad") << endl;
	cout << wd.search(".ad") << endl;
	cout << wd.search("b..") << endl;
	*/

	wd.addWord("run");
	wd.addWord("rune");
	wd.addWord("runner");
	wd.addWord("runs");
	wd.addWord("add");
	wd.addWord("adds");
	wd.addWord("adder");
	wd.addWord("addee");
	cout << wd.search("r.n") << endl;
	cout << wd.search("ru.n.e") << endl;
	cout << wd.search("add") << endl;
	cout << wd.search("add.") << endl;
	cout << wd.search("adde.") << endl;
	cout << wd.search(".an.") << endl;
	cout << wd.search("...s") << endl;
	cout << wd.search("....e.") << endl;
	cout << wd.search(".......") << endl;
	cout << wd.search("..n.r") << endl;

	return 0;
}
