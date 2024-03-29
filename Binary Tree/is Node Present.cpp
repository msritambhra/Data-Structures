#include <iostream>
#include <queue>
#include<BinaryTreeNode.h>
using namespace std;


bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    
    if(root==NULL)
        return false;
    
    if(root->data == x)
        return true;
    
    if(isNodePresent(root->left, x) || isNodePresent(root->right, x))
        return true;
    else
        return false;

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
    int x;
    cin >> x;
    if(isNodePresent(root, x)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    
}
