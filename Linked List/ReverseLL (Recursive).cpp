// Reverse Linked List  a. Using recursion  b. Without using recursion
#include <iostream>

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

node *reverse_linked_list_rec(node *head){
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node * head1 = reverse_linked_list_rec(head->next);
    
    node* temp = head1;
    
    while(temp->next!=NULL){
        temp = temp->next;
    }
    
    temp->next=  head;
    head->next = NULL;
    
    return head1;
}



node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}



