//Eliminate duplicates from a sorted linked list
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


node* eliminate_duplicate(node* head){
    
    node *slow = head;
    node* fast = head;
    int count = 0;
    int current ;

    while( slow->next!=NULL){
        current = slow->data;
        while(fast!=NULL && fast->data == current )
            fast = fast->next;
        slow->next = fast;
        if(fast!=NULL)
            slow = fast;
        
    }
    return head;
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
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

