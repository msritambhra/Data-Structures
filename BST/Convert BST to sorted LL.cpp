#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    
    if(root==NULL){
        return NULL;
    }
    
    //recursively call ConstructBST on left and right child
    Node<int> * left = constructBST(root->left);
    Node<int> * right = constructBST(root->right);
    
    // Create a LL node with root's data
    Node<int> * head = new Node<int>(root->data);
    
    // Connect result of right subtree to the head of LL
    head->next = right;
    
    //traversing the  resultant LL of left subtree till the last node
    Node<int> * temp = left;
    
    while(temp!=NULL){
        if(temp->next==NULL)
            break;
        temp = temp->next;
    }
    
    //Inserting the LL of left subtree before head if its not empty
    if(temp!=NULL){
    temp->next = head;
    
    head = left;}
    
    return head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}
