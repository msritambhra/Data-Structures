#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;


void printLevelATNewLine(BinaryTreeNode<int> *root) {
    
    if(root==NULL){
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);........
    
    while(!pendingNodes.empty()){
        
        BinaryTreeNode<int> * top = pendingNodes.front();
        pendingNodes.pop();
        if(top==NULL){
            
            if(pendingNodes.empty())
                break;
            
            cout<<endl;
            pendingNodes.push(NULL);
            continue;
        }
        
        cout<<top->data<<" ";
        
        if(top->left!=NULL)
            pendingNodes.push(top->left);

        
        if(top->right!=NULL)
            pendingNodes.push(top->right);
            
    }
    
    return;

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
    printLevelATNewLine(root);
}
