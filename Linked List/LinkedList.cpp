#include <iostream>
using namespace std;
#include "Node.cpp"

//Delete Node Iterative 
Node* deleteNode(Node *head, int i) {
    
    if(head==NULL)
        return NULL;
    
    Node * temp = head;
    Node * prev = NULL;
    int current = 0;
    
    if (temp!=NULL && i==0) 
    { 
        head = temp->next;   
        free(temp);              
        return head; 
    } 
    
    while(temp!=NULL){
        
        if(i==current){
            Node * curr = temp;
            prev->next = temp->next;
            delete curr;
            return head;
        }
        
        prev = temp;
        temp = temp->next;
        current +=1;
        
    }
    
    return head;
}

//Recursive Delete Node
Node* deleteNode_rec(Node *head, int i) {
    
    if(head==NULL)
        return NULL;
    
    if(i==0){
        head = head->next;
        return head;
    }
    
    Node * result = deleteNode(head->next,i-1);
    head->next = result;
    
    return head;
}

// Print ith Node
void printIthNode(Node *head, int i) {
    
    int curr = 0;
    Node*temp = head;
    
    while(temp!=NULL){
        
        if (curr == i){
            cout<<temp->data;
            return;
        }
        
        curr++;
        temp = temp->next;  
    }    
}

//Length of Linked List Recursive
int length(Node *head) {
    
    if(head==NULL)
        return 0;
    
    return 1 + length(head->next);
}


//Length of Linked List Iterative
int length(Node *head) {
    
    int len = 0 ;
    Node *temp = head;
    
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    
    return len;
}


// Take Input Function
Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
		}
		else {
			Node *temp = head;
			while(temp -> next != NULL) {
				temp = temp -> next;
			}
			temp -> next = newNode;
		}

		cin >> data;
	}
	return head;
}

// Take Input Function using tail node
Node* takeInput_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
		}

		cin >> data;
	}
	return head;
}

// Print the Linked List
void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

int main() {

	Node *head = takeInput_Better();
	print(head);
	
	/*
	// Statically
	Node n1(1);
	Node *head = &n1;

	Node n2(2);

	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	print(head);

	*/

	/*

	// Dynamically
	Node *n3 = new Node(10);
	Node *head = n3;
	
	Node *n4 = new Node(20);
	n3 -> next = n4;

	*/

}

