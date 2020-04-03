#include <iostream>
#include <queue>
#include<BinaryTreeNode.h>
using namespace std;


/*
void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    
    if(root==NULL)
        return;
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        
        
        if(front->left!=NULL && front->right==NULL){
            cout<<front->left->data;
            cout<<endl;
        }
        if(front->left==NULL && front->right!=NULL){
            cout<<front->right->data;
            cout<<endl;
        }
         if(front->left!=NULL)
             pendingNodes.push(front->left);
        
        if(front->right!=NULL)
             pendingNodes.push(front->right);
    }
    
}*/

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    
    if(root==NULL)
        return;
  
    if(root->left!=NULL&&root->right!=NULL){
        nodesWithoutSibling(root->left);
        nodesWithoutSibling(root->right);

    }
  
    if(root->left==NULL&&root->right!=NULL){
        cout<<root->right->data<<endl;
        nodesWithoutSibling(root->right);
    }
    
    else if(root->left!=NULL&&root->right==NULL){
        cout<<root->left->data<<endl;
        nodesWithoutSibling(root->left);
  
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
    nodesWithoutSibling(root);
}

