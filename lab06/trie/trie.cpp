#include "trie.h"
#include <iostream>

Trie::Trie()
{
	root = NULL;
}

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
  TrieNode* ret = new TrieNode;
  return ret;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void Trie::insert(struct TrieNode* root, const std::string key)
{
	struct TrieNode *curr = root,*prev=nullptr;
	int i=0;
	while(curr!=nullptr&&i<key.length()){
		int alp_num = key[i]-'a'; i++;
		prev=curr;
		curr=curr->children[alp_num];
	}
	
	
}

bool Trie::search(struct TrieNode *root, std::string key)
{
	return false; //dummy return
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool Trie::isLastNode(struct TrieNode* root)
{
	return false; //dummy return
}

// Recursive function to print auto-suggestions for given node.
void Trie::suggestionsRec(struct TrieNode* root, std::string currPrefix)
{

}

// print suggestions for given query prefix.
// return 0 if nothing is printed
// return 1 if atleast one word is printed
int Trie::printAutoSuggestions(TrieNode* root, const std::string query)
{
	return 0; //dummy return
}
