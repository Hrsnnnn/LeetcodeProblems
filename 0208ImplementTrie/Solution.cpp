#include<iostream>
#include<map>

using namespace std;

class TrieNode {
public:
    bool isWord = false;
    char val;
    map<char, TrieNode*> children;
    TrieNode() { isWord = false; }
    TrieNode(char c) { val = c; isWord = false; }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i=0;i<word.size();i++) {
            if(tmp->children.count(word[i])) {
                tmp = tmp->children[word[i]];
            } else {
                tmp->children[word[i]] = new TrieNode(word[i]);
                tmp = tmp -> children[word[i]];
            }
        }
        tmp -> isWord = true;
    }
    
    bool search(string word) {
        TrieNode* tmp = root;
        for(int i=0;i<word.size();i++) {
            if(tmp->children.count(word[i])) {
                tmp = tmp->children[word[i]];
            } else return false;
        }
        return tmp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for(int i=0;i<prefix.size();i++) {
            if(tmp->children.count(prefix[i])) {
                tmp = tmp->children[prefix[i]];
            } else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */