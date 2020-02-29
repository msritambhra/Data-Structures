#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>


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

using namespace std;


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


void convertToArray(BinaryTreeNode<int>*root, vector<int> &v){
     
    
    if(root==NULL)
        return;
    convertToArray(root->left,v);
    v.push_back(root->data);
    convertToArray(root->right,v);
  
    
}


void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    
    if(root==NULL)
        return;
    
    vector<int> output;
    convertToArray(root,output);
    
    sort(output.begin(),output.end());
    
    int i =0,j = output.size()-1;
    
    while(i<j){
        if(output[i]+output[j]==sum){
            cout<<min(output[i],output[j])<<" "<<max(output[i],output[j])<<endl;
            i++;
            j--;
        }
        else if (output[i]+output[j] > sum){
            j--;
        }
        else
            i++;
    }
    

}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
