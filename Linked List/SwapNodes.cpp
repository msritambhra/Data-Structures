//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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

node* swap_nodes(node *head,int i,int j){
    if(head==NULL)
        return head;
    
    node *temp = head;
    node* prev = NULL;
    node* node1 = NULL, *node2 = NULL, *node1_prev = NULL, *node2_prev = NULL;
    
    int pos = 0;
    
    while(temp!=NULL){
        if(pos == i){
            node1_prev = prev;
            node1 = temp;
        }
        
        else if(pos ==j){
            node2_prev = prev;
            node2 = temp;
        }
        
        prev = temp;
        temp = temp->next;
        pos++;
    }
    
    if(node1_prev == NULL){
        head = node2;
    }
    else{
        node1_prev->next = node2;
    }
    
     if(node2_prev == NULL){
        head = node1;
    }
    else{
        node2_prev->next = node1;
    }
    
    node *temp2 = node1->next;
    node1->next = node2->next;
    node2->next = temp2;
    
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

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}

