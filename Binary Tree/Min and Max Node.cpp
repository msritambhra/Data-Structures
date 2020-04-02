#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include<climits>
using namespace std;

class PairAns {
    public :
        int min;
        int max;
 };
 

PairAns minMax(BinaryTreeNode<int> *root) {
   
    if(root==NULL){
        PairAns p;
        p.min = INT_MAX;
        p.max = INT_MIN;
        return p;
    }
    
    PairAns leftAns = minMax(root->left);
    PairAns rightAns = minMax(root->right);
    
    PairAns ans;
    
    ans.max = max(root->data,max(leftAns.max,rightAns.max));
    ans.min = min(root->data,min(leftAns.min,rightAns.min));
    
    return ans;
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
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}

