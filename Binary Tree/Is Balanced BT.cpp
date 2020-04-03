#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;


pair<int,bool> isBalancedHelper(BinaryTreeNode<int> *root){
    
    if(root==NULL){
        pair<int,bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    
    pair<int,bool> leftAns = isBalancedHelper(root->left);
    pair<int,bool> rightAns = isBalancedHelper(root->right);
    
    int leftHeight = leftAns.first;
    int rightHeight = rightAns.first;
    
    int height = 1 + max(leftHeight, rightHeight);
    
    int diff = leftHeight-rightHeight;
    
    bool bal = false;
    if(leftAns.second==true && rightAns.second==true && diff<=1 && diff>=-1)
        bal = true;
    
    pair<int,bool> ans;
    ans.first = height;
    ans.second = bal;
    
    return ans;
} 


bool isBalanced(BinaryTreeNode<int> *root) {
    
    if(root==NULL)
        return true;
    
    pair<int,bool> ans = isBalancedHelper(root);
    
    return ans.second;

}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
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
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}
