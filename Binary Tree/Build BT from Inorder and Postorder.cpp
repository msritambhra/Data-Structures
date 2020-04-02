#include <iostream>
#include <queue>
#include<BinaryTreeNode.h>
using namespace std;

BinaryTreeNode<int>* helper(int *postorder,int *inorder,int ps, int pe, int is, int ie){
 if(is>ie)
   return NULL;
    
  int rootdata=postorder[pe];
  int rootindex;
  
  for(int i=is;i<=ie;i++){
     if(inorder[i]==rootdata)
     {
        rootindex=i;
       break;
     }
      
     
  }
  int lps=ps;
  int lis=is;
  int lie=rootindex-1;
  int ris=rootindex+1;
  int rie=ie;
  int rpe=pe-1;
  int lpe=lie-lis+lps;
  int rps=lpe+1;
    
  BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootdata);
  root->left=helper(postorder,inorder,lps,lpe,lis,lie);
  root->right=helper(postorder,inorder,rps,rpe,ris,rie);
  
  return root;
  
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    
  return helper(postorder,inorder,0,postLength-1,0,inLength-1);

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
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>pre[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}


