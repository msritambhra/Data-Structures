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

Node* mergeTwoLLs(Node *head1, Node *head2){
    if(head1==NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    Node *head = NULL;
    Node *tail = NULL;

    if(head1->data < head2->data){
        head = head1;
        head1 = head1->next;
    }

    else{
        head = head2;
        head2 = head2->next;
    }


    tail = head;

    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    if(head1==NULL){
        tail->next = head2;
    }

    if(head2==NULL)
        tail->next = head1;
    return head; 
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
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

