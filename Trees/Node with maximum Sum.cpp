#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

template <typename T>
class Pair{
    public:
        int sum;
        TreeNode<T> * node;
};



Pair<int>* maxSumNodeHelper(TreeNode<int>* root){
    if(root==NULL)
        return NULL;

    int sum = root->data;
    for(int i = 0 ; i<root->children.size(); i++){
        sum+= root->children.at(i)->data;
    }
    
    Pair<int> * ans = new Pair<int>();
    ans->node = root;
    ans->sum = sum;
    
    for(int i = 0; i<root->children.size(); i++){
        Pair<int>* childAns = maxSumNodeHelper(root->children.at(i));
        if(ans->sum < childAns->sum){
            ans = childAns;
        }
    }
    
    return ans;
}



TreeNode<int>* maxSumNode(TreeNode<int> *root){
    if(root==NULL)
        return NULL;
    Pair<int> * ans = maxSumNodeHelper(root);
    return ans->node;
}


/*
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    
    if(root==NULL)
        return root;
    
    int sum = root->data;
    for(int i = 0; i<root->children.size(); i++){
        sum+=root->children.at(i)->data;
        
    }
    
    TreeNode<int> * ans  = root;
    
    for(int i = 0 ; i<root->children.size(); i++){
        
        TreeNode<int> * x = maxSumNode(root->children.at(i));
        int xsum = x->data;
        
        for(int j = 0 ; j< x->children.size(); j++)
            xsum+=x->children.at(j)->data;
        
        if(xsum>sum){
            sum = xsum;
            ans = x;
        }
        
    }
    
    return ans;
}*/




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


