#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
#include<vector>

template <typename T>

class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<node<int>*> result;
    
    if(root==NULL){
        node<int>* n = NULL;
        result.push_back(n);
        return result;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    node<int>* head = NULL;
    node<int>* temp = head;
    
    while(!pendingNodes.empty()){
        
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front==NULL){
            
            temp->next = NULL;
            result.push_back(head);
            
            if(pendingNodes.empty())
                break;
            
            head = NULL;
            temp = NULL;
            
            pendingNodes.push(NULL);
            continue;
        }
        
        node<int>* newNode = new node<int>(front->data);
        
        if(head==NULL){
            head = newNode;
            temp = head;
        }
        
        else{
            temp->next = newNode;
            temp = temp->next;
        }
        
        if(front->left!=NULL)
            pendingNodes.push(front->left);
        
        if(front->right!=NULL)
            pendingNodes.push(front->right);
        
        
    }
    
    return result;

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

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}