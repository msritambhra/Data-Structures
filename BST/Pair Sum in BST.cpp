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

// This solution has Time Complexity: O(N) & Space Complexity: O(N).

void convertToArray(BinaryTreeNode<int>* root, vector<int>  &ans){
    if(root==NULL)
        return;
    convertToArray(root->left,ans);
    ans.push_back(root->data);
    convertToArray(root->right,ans);
}


void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    
	if(root==NULL)
        return;
    
    vector<int>  ans;
    convertToArray(root,ans);
    
    int i =0 ,j = ans.size()-1;
    while(i<j){
        int sum = ans[i]+ans[j];
        
        if(sum==s){
            cout<<ans[i]<<" "<<ans[j]<<endl;
            i++;
            j--;
            
        }
        else if(sum>s)
            j--;
        else
            i++;
    }
           

}

*/



//The following solution improves on the Space Complexity of previous solution.


#include<stack>

int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s){
    
    if(root==NULL)
        return;
    
    stack<BinaryTreeNode<int>*> inOrder;
    stack<BinaryTreeNode<int>*> inOrder_rev;
    
    BinaryTreeNode<int>* temp = root;
    
    while(temp!=NULL){
        inOrder.push(temp);
        temp = temp->left;
        
    }
    temp = root;
    while(temp!=NULL){
        inOrder_rev.push(temp);
        temp = temp->right;
    }
    
    int count = 0 ;
    int totalCount = countNodes(root);
    
    
    while(count<totalCount -1 ){
        
        BinaryTreeNode<int>* top1 = inOrder.top();
        BinaryTreeNode<int>* top2 = inOrder_rev.top();
        
        int sum = top1->data + top2->data;
        
        if(sum == s){
            cout<<top1->data<<" "<<top2->data<<endl;
            inOrder.pop();
            inOrder_rev.pop();
            
            if(top2->left!=NULL){
                top2 = top2->left;
                while(top2!=NULL){
                    inOrder_rev.push(top2);
                    top2 = top2->right;
                }
            }
            
            count++;
            
            if(top1->right!=NULL){
                top1 = top1->right;
                while(top1!=NULL){
                    inOrder.push(top1);
                    top1 = top1->left;
                }
            }
            
            count++;
            
              
        }
        
        else if(sum>s){
            
            inOrder_rev.pop();
            if(top2->left!=NULL){
                top2 = top2->left;
                while(top2!=NULL){
                    inOrder_rev.push(top2);
                    top2 = top2->right;
                }
            }
            
            count++;
        }
        
        else {
            inOrder.pop();
            if(top1->right!=NULL){
                top1 = top1->right;
                while(top1!=NULL){
                    inOrder.push(top1);
                    top1 = top1->left;
                }
            }
            
            count++;
        }
        
        
        
    }
    
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
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}

