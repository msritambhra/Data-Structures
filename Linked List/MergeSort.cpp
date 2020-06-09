//merge sort recursive
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

node* midpoint(node *head){
    
    node* slow=head;
    node* fast=head;
    if(head!=NULL){

        while(fast!=NULL &&fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

    }

    return slow;

}

node* merge(node *head1, node *head2) {
    node*head=NULL;
    node *tail=NULL;

    if(head1->data > head2->data)
    {
        head=head2;
        tail=head2;
        head2=head2->next;
    }
    else
    {
        head=head1;
        tail=head1;
        head1=head1->next;
    }

    while(head1!=NULL && head2!=NULL)

    {
        if(head1->data < head2->data)
        {  
            tail->next=head1;

            tail=head1;
            head1=head1->next;
        }
        else
        {
            tail->next=head2;

            tail=head2;
            head2=head2->next;
        }
    }

    if(head1!=NULL )
    {
        tail->next=head1;
        tail=head1;

    }

    if(head2!=NULL)
    {
        tail->next=head2;
        tail=head2;

    }
    return head;
}




node* mergeSort(node *head) {
    if(head==NULL||head->next==NULL)
        return head;

    node*mid=midpoint(head);

    node *a=mid->next;
    mid->next=NULL;

    node *h1=mergeSort(head);
    node*h2= mergeSort(a);

    node *head= merge(h1,h2);
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
    head= mergeSort(head);
    print(head);
    return 0;
}

