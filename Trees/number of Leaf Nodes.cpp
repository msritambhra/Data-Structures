
#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;



int numLeafNodes(TreeNode<int>* root) {
   
    if(root==NULL)
        return 0;
    if(root->children.size()==0)
        return 1;
    int ans = 0;
    
    for(int i = 0 ; i< root->children.size(); i++){
        ans += numLeafNodes(root->children.at(i));    
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
    cout << numLeafNodes(root) << endl;
}