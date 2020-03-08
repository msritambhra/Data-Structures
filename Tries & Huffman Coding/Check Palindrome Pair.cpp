#include <iostream>
#include <string>
#include <vector> 
#include<algorithm>
using namespace std;

#include "TrieNode.h"



class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
			root->childCount++;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	bool search(TrieNode *root, string word) {
        if(word.size()==0){
            return root->isTerminal;
        }
        
       
        
        int index = word[0] - 'a';
        
        TrieNode * child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else
            return false;
        
        return search(child , word.substr(1));
    }
    
    bool search(string word){
        return search(root,word);
    }

	bool findIfPalindromePair(vector<string> arr) {
		if(arr.size()==0 )
            return false;
        string word;
        for(int i =0 ; i < arr.size(); i++){
            
            word = arr[i];
            
            
            if(search(word.substr(0,word.size())))
                    return true;
                
            
            
            reverse(word.begin(), word.end());
            
            if(word==arr[i])
                return true;
            
            insertWord(word);
            insertWord(word.substr(1));
                
        
         }
        
        return false;
        
	}
};


int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}


