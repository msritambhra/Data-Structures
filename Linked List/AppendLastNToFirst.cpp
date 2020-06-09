//Append the last n elements of a linked list to the front
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


node* append_LinkedList(node* head,int n){

    node *slow = head;
    node *fast = head;
    
    int count = 0;
    
    while(count<n){
        fast = fast->next;
        count++;
    }
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    
    node *head2 = slow->next;
    slow->next = NULL;

    fast->next = head;
    head = head2;
    
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
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
