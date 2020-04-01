/*

Given two Generic trees, return true if they are structurally identical 
i.e. they are made of nodes with the same values arranged in the same way.

*/

#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;


bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    
    if(root1->data!=root2->data || root1->children.size()!=root2->children.size())
        return false;
    
    bool ans = true;
    for(int i = 0; i<root1->children.size();i++){
        if(isIdentical(root1->children.at(i),root2->children.at(i)))
            ans = true;
        else
            ans = false;
    }
    
    return ans;

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
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


