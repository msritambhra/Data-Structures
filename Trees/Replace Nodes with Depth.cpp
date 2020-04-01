/*

In a given Generic Tree, replace each node with its depth value. 
You need to just update the data of each node, no need to return or print anything.

*/

#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

void helper(TreeNode<int>* root , int depth){
    if(root==NULL)
        return;
    
    root->data = depth;
    for(int i = 0 ; i<root->children.size(); i++){
        helper(root->children.at(i),depth+1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){    
    
    if(root==NULL)
        return;
    
    return helper(root,0);

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
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}



