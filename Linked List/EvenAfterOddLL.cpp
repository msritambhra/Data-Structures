//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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

node* arrange_LinkedList(node* head){

    if(head==NULL)
        return head;

    node*eh = NULL;
    node*et = NULL;
    node*oh = NULL;
    node*ot = NULL;

    while(head!=NULL){

        if(head->data%2==0){
            if(eh==NULL)
                eh = head;    
            else
                et->next = head;

            et = head;
        }
        else{

            if(oh==NULL)
                oh = head;
            else
                ot->next = head;

            ot = head;
        }

        head = head->next;

    }


    if(eh==NULL)
        return oh;
    if(oh==NULL)
        return eh;

    et->next = NULL;
    ot->next = eh;

    head = oh;

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
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
