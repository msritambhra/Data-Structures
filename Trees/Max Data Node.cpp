

#include <iostream>
#include<TreeNode.h>
using namespace std;
#include <vector>

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    
    if(root == NULL)
        return root;
    
    TreeNode<int>* max = root;
    TreeNode<int>* maxChild;
    for(int i = 0 ; i<root->children.size(); i++){
        maxChild = maxDataNode(root->children.at(i));
        if(max->data<maxChild->data)
            max = maxChild;
    }
    
    return max;

}


#include <queue>


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
    TreeNode<int>* ans = maxDataNode(root);
    if(root != NULL) {
       	cout << ans -> data;
    }
}
