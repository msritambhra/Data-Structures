/*

Given a generic tree, find and return the node with second largest value in given tree. 
Return NULL if no node with required value is present.

*/

#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;
#include<climits>


class Pair{
    public:
    TreeNode<int>* first;
    TreeNode<int>* second;
};

Pair* secondLargestHelper(TreeNode<int> *root){
    
    if(root==NULL)
      return NULL;
    
    Pair* ans = new Pair();
    ans->first = root;
    ans->second = NULL;
    
    for(int i = 0; i < root->children.size(); i++){
        Pair *childAns = secondLargestHelper( root->children.at(i));
        
        if(ans->first->data<childAns->first->data){
            if(childAns->second == NULL){
                ans->second = ans->first;
                ans->first = childAns->first;
            }
            else{
                if(ans->first->data<childAns->second->data){
                    ans->first = childAns->first;
                    ans->second = childAns->second;
                }
                else{
                    ans->second = ans->first;
                    ans->first = childAns->first;
                }
            }
        }
        else{
             if((ans->first->data!=childAns->first->data)&&((ans->second==NULL)||(childAns->first->data>ans->second->data))){
                ans->second = childAns->first;
            }
        }
    }
    
    return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    if(root==NULL)
        return NULL;
    
    Pair * ans = secondLargestHelper(root);
    
    return ans->second;
    

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
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}



