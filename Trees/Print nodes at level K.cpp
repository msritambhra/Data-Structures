
#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;



void printAtLevelK(TreeNode<int>* root, int k) {
    
    if(root==NULL)
        return;
    
    if(k==0)
        cout<<root->data<<" ";
	return;
    
    for(int i = 0; i<root->children.size(); i++){
        printAtLevelK(root->children.at(i),k-1);
    }

}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout<<"Enter the level of nodes to print:";
    int k;
    cin>>k;
    cout << printAtLevelK(root,k) << endl;
}
