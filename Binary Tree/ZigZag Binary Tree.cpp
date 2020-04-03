#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
#include<stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    
    if(root==NULL)
        return;
   
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    bool flag = false;
    
    s1.push(root);
    
    
    while(!((s1.size()==0 )&& (s2.size()==0))){
        if(flag==false){
            BinaryTreeNode<int>* top = s1.top();
            s1.pop();
            
            if(top->left!=NULL)
                s2.push(top->left);
            if(top->right!=NULL)
                s2.push(top->right);
            
            cout<<top->data<<" ";
            if(s1.empty()){
                if(s2.empty())
                    break;
                cout<<endl;
                flag = !flag;
            }
            
        }
        
        else{
            
            BinaryTreeNode<int>* top = s2.top();
            s2.pop();
            
            if(top->right!=NULL)
                s1.push(top->right);
            
            if(top->left!=NULL)
                s1.push(top->left);
            
            
            cout<<top->data<<" ";
            if(s2.empty()){
                if(s1.empty())
                    break;
                cout<<endl;
                flag = !flag;
            }
            
        }
    }
    
    
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
    zigZagOrder(root);
}
