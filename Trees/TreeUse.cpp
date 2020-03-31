#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){

	int  rootData;
	cout<<"Enter root data:";
	cin>>rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		TreeNode<int>* node = pendingNodes.front();
		pendingNodes.pop();
		int n;
		cout<<"Enter num of children of "<<node->data<<":"<<endl;
		cin>>n;
		for(int i = 0; i<n; i++){
			int childData;
			cout<<"Enter "<<i<<" th child of "<<node->data<<endl;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			node->children.push_back(child);
			pendingNodes.push(child);
		}
			
	}

	return root;
}

void printLevelWise(TreeNode<int>* root) {
    
    if(root==NULL)
        return;
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i = 0; i<front->children.size();i++){
            cout<<front->children.at(i)->data;
            pendingNodes.push(front->children.at(i));
            if(i!=front->children.size()-1)
                cout<<",";
            
        }
        
        cout<<endl;
    }
}


TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

int main() {
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInput();
	printTree(root);
	// TODO delete the tree
}

