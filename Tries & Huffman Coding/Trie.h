class Trie {
	TrieNode *root;

	public :

	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
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
		}
		
		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		insertWord(root, word);
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

    	void remove(TrieNode *root, string word){
        
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }
        
        TrieNode *child;
        int index = word[0]-'a';
        if(root->children[index]!=NULL)
            child = root->children[index];
        else
            return; //word not found
        
        remove(child,word.substr(1));
        
        
        //De-allocating child if its useless
        
        if(child->isTerminal == false){
            
            for(int i=0; i<26; i++){
                
                if(child->children[i]!=NULL)
                    return;
            }
            
            delete child;
            root->children[index] = NULL;
        }
        
        
    }
    
    void remove(string word){
        return remove(root, word);
    }
};
