#include <iostream>
#include <queue>
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
};


/*

bool isBST(BinaryTreeNode<int> *root){
    if(root==NULL)
        return true;
    
    if((root->left && root->data<root->left->data) || (root->right && root->data>root->right->data))
        return false;
    
    if(!isBST(root->left) || !isBST(root->right))
        return false;
    return true;
}

int height(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + max(rightHeight,leftHeight);
}
int largestBSTSubtree(BinaryTreeNode<int> *root){
    
    if(root==NULL)
        return 0;
    if(isBST(root))
        return height(root);
    
    int leftBST_Height = largestBSTSubtree(root->left);
    int rightBST_Height = largestBSTSubtree(root->right);
    
    return max(leftBST_Height, rightBST_Height);
    
    
        
} */


#include<climits>


class PairAns{
    public:
    	int max;
    	int min;
        bool isBST;
    	int height;
};

PairAns largestBSTSubtreeHelper(BinaryTreeNode<int>* root){

    if(root==NULL){
        PairAns ans;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.height = 0;
        ans.isBST = true;
        return ans;
    }
    
    PairAns leftAns = largestBSTSubtreeHelper(root->left);
    PairAns rightAns = largestBSTSubtreeHelper(root->right);
    
    PairAns ans;
    ans.min = min(root->data,min(leftAns.min,rightAns.min));
    ans.max = max(root->data,max(leftAns.max,rightAns.max));
    
    if(leftAns.isBST && rightAns.isBST){
        if(root->data > leftAns.max && root->data < rightAns.min){
            ans.isBST = true;
        	ans.height = 1 + max(leftAns.height, rightAns.height);
        }
        else{
            ans.isBST = false;
            ans.height = max(rightAns.height,leftAns.height);
        }
    }
    
    else{
        ans.isBST = false;
        ans.height = max(leftAns.height,rightAns.height);
        
    }
    
    
    return ans;   
    
}


int largestBSTSubtree(BinaryTreeNode<int> *root){
    
    if(root==NULL)
        return 0;
    
    PairAns ans =  largestBSTSubtreeHelper(root);
    
    return ans.height;
    
    
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
    cout << largestBSTSubtree(root);
    delete root;
}
