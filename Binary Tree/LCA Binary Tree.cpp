#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
    }
};




/*bool findPath(BinaryTreeNode <int>* root, int data, vector<int> &path){
    
    if(root==NULL)
        return false;
    
    path.push_back(root->data);
    if(root->data==data)
        return true;
    
    if((root->left&&findPath(root->left,data,path)) || (root->right&&findPath(root->right,data,path)))
        return true;

    
    path.pop_back();
    return false;
}


int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    
   
    if(root==NULL)
        return -1;
    
    vector<int> path1, path2;
     if( !findPath(root,val1,path1) || !findPath(root,val2,path2))
         return -1;
    
    int i =0;
    for(i=0;i<path1.size() && i<path2.size();i++){
        if(path1[i]!=path2[i])
            break;
    }
    
    return path1[i-1];

}*/

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    
    if(root==NULL)
        return -1;
    
    if(root->data==val1 || root->data==val2)
        return root->data;
    int lcaLeft = lcaBinaryTree(root->left,val1,val2);
    int lcaRight = lcaBinaryTree(root->right,val1,val2);
    
    if(lcaLeft==-1 && lcaRight==-1)
        return -1;
    else if(lcaLeft==-1)
        return lcaRight;
    else if(lcaRight==-1)
        return lcaLeft;
    else
        return root->data;
    
}



BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << lcaBinaryTree(root, a, b);
    delete root;
}