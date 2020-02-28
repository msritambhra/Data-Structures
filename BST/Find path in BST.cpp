#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;
#include <vector>


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    
    if(root==NULL){
        return NULL;
    }
    
    // Case 1: If root matches the data , vector with just the data is returned
    if(root->data==data){
        vector<int> * v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    
    // Case 2: If root's data is greater than the given value
    else if(data<root->data){
        vector<int> * left = findPath(root->left,data);
        // If the value is found in left subtree, vector with the data is returned
        if(left!=NULL){
            left->push_back(root->data);
            return left;
        }
        // If value not found in left subtree, empty vector is returned
        else{
            return NULL;
        }
        
    }
    
    // Case 3: If root's data is smaller than the given value
    else{
        vector<int> * right = findPath(root->right,data);
    
        // If the value is found in right subtree, vector with the data is returned
        if(right!=NULL){
            right->push_back(root->data);
            return right;
        }
        
         // If value not found in right subtree, empty vector is returned
        else{
            return NULL;
        }
        
        
    }

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = findPath(root, k);
    if(output != NULL) {
        for(int i = 0; i < output -> size(); i++) {
            cout << output -> at(i) << endl;
        }
    }
    delete root;
}
