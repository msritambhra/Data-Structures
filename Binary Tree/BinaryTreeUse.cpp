#include <iostream>
#include "BinaryTreeNode.h"
#include<queue>
using namespace std;

int countNodes(BinaryTreeNode<int> *root) {

	if(root==NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);

}

void printLevelWise(BinaryTreeNode<int> *root) {
    
    if(root==NULL)
        return;
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        
        cout<<front->data<<":";
        
        if(front->left!=NULL){
            cout<<"L:"<<front->left->data;
            pendingNodes.push(front->left);
        }
        else
            cout<<"L:"<<-1;
        
        if(front->right!=NULL){
            cout<<",R:"<<front->right->data;
            pendingNodes.push(front->right);
        }
        else
            cout<<",R:"<<-1;
        
        cout<<endl;
        
    }

}


BinaryTreeNode<int>* takeInputLevelWise(){

	int rootData;
	cout<<"Enter root data:";
	cin>>rootData;
	cout<<endl;
	
	if(rootData==-1)
		return NULL;

	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()){

		BinaryTreeNode<int>*  front = pendingNodes.front();
		pendingNodes.pop();

		cout<<"Enter left Child of "<<front->data<<":";
		int leftchild;
		cin>>leftchild;

		if(leftchild!=-1){
			BinaryTreeNode<int>*  left = new BinaryTreeNode<int>(leftchild);
			front->left = left;
			pendingNodes.push(left);
		}

		cout<<endl<<"Enter right Child of "<<front->data<<":";
		int rightchild;
		rightchild;

		if(rightchild!=-1){
			BinaryTreeNode<int>*  right = new BinaryTreeNode<int>(rightchild);
			front->right = right;
			pendingNodes.push(right);
		}
		
		
	} 

	return root;


}


void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;

	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

int main() {
	
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}

