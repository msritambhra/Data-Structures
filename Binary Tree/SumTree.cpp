/*

Write a function that returns true if the given Binary Tree of size N is SumTree else return false.
A SumTree is a Binary Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree .
An empty tree is SumTree and sum of an empty tree can be considered as 0.
A leaf node is also considered as SumTree.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isSumTree(struct Node* node);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout <<isSumTree(root) << endl;
    }
    return 1;
}


pair<bool,int> isSumTreeHelper(Node * root){
    
    if(root==NULL){
        pair<bool,int> ans;
        ans.first = true;
        ans.second = 0;
        return ans;
    }
    
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> ans;
        ans.first = true;
        ans.second = root->data;
        return ans;
    }
    
    pair<bool,int> leftAns = isSumTreeHelper(root->left);
    pair<bool,int> rightAns = isSumTreeHelper(root->right);
    
    pair<bool,int> ans;
    ans.second = leftAns.second + rightAns.second;
    if(leftAns.first && rightAns.first && root->data == ans.second)
        ans.first = true;
    else 
        ans.first = false;
    
    ans.second+=root->data;
    
    return ans;

    
}


bool isSumTree(Node* root)
{
     if(root==NULL)
        return true;
    
    pair<bool,int> ans = isSumTreeHelper(root);
    
    return ans.first;
}