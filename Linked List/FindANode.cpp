#include <iostream>

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

int indexOfNIter(Node *head, int n)
{
  Node *temp  = head;
  int count = 0;
  while(temp!=NULL){
      if (temp->data==n){
          return count;
      }
      count++;
      temp = temp->next;
      
     
  }
  return -1;
   
    
}


Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int n;
    cin >> n;
    cout << indexOfNIter(head, n);
    
}

