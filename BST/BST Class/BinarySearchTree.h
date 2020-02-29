#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

/* 

This class used nodes of class BinaryTeeNode to construct a BST 

Methods in Class BST:

1. hasData(int data) : Given a data, finds if its present in BST or not.

2. insert(int data) : Given data, inserts it in the BST at correct position.

3. deleteData(int data) : given data, deletes it from BST, and rearranges BST.

4. printTree() : Print the detail of every Node present in BST in format of N:L:x,R:y where x and y are data of left and right node.

*/	

class BST {
	BinaryTreeNode<int>* root;
    
    private:
    
    bool searchHelper(int data,BinaryTreeNode<int>* node){
            if(node==NULL)
                return false;
            
            if(node->data == data)
                return true;
        
            else if(data<node->data){
                return searchHelper(data,node->left);
            }
        
            else{
                return searchHelper(data,node->right);
            }
    }
    
    BinaryTreeNode<int>* insertHelper(int data , BinaryTreeNode<int>* node){
        if(node==NULL){
                BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
                return newNode;
            }
        
        if(node->data < data){
            //BinaryTreeNode<int>* newNode = insertHelper(data,root->right);
            node->right = insertHelper(data,node->right);
            return node;
        }
        
        else if(node->data > data){
            //BinaryTreeNode<int>* newNode = insertHelper(data,root->left);
            node->left = insertHelper(data,node->left);
            return node;
        }
        
        
        
    }
    
    BinaryTreeNode<int>* searchMin(BinaryTreeNode<int>* node){
        if(node==NULL)
            return NULL;
        if(node->left==NULL)
            return node;
        else
            return searchMin(node->left);
    }
    
    BinaryTreeNode<int>* deleteHelper(int data, BinaryTreeNode<int> * node){
        if(node==NULL)
            return NULL;
        
        if(node->data == data){
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            
            else if(node->right == NULL){
                BinaryTreeNode<int> * temp = node->left;
                node->left = NULL ;
                delete node;
                return temp;
            }
            
            else if(node->left ==NULL){
                BinaryTreeNode<int> * temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            
            else{
                BinaryTreeNode<int> * minNode = searchMin(node->right);
                int x = minNode->data;
                node->data = x;
                node->right = deleteHelper(x,node->right);
                return node;
            }
            
        }
        else if(node->data > data){
            node->left =  deleteHelper(data,node->left);
            return node;
        }
        else{
            node->right =  deleteHelper(data,node->right);
            return node;
        }
    }
    
    void printTreeHelper(BinaryTreeNode<int>* node){
        if(node==NULL){
                return;
            }
            
            cout<<node->data<<":";
            if(node->left!=NULL){
                cout<<"L:"<<node->left->data<<",";
            }
            if(node->right!=NULL){
                cout<<"R:"<<node->right->data;
            }
            cout<<endl;
            
            printTreeHelper(node->left);
            printTreeHelper(node->right);
    }
    
    public:
    
        BST(){
            root = NULL;
        }
        
        ~BST(){
            
            delete root;
        }
    
        void insert(int data){
            
            root = insertHelper(data,root);
            return;
            
        }
    
        bool hasData(int data){
            return searchHelper(data,root);
        }
    
        void deleteData(int data){
            root = deleteHelper(data,root);
            return;
        }
    
        void printTree(){
            printTreeHelper(root);
            
        }
};
