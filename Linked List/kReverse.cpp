//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

node* reverse(node* head){
 
    node*current=head, *prev = NULL, *next = NULL;
    while(current!=NULL){
        
        next=current -> next;
        current -> next = prev;

        prev = current;
		current =next;
    }
    
    return prev;
}


node* kReverse(node*head,int n){   
    if(head->next==NULL||head==NULL)
        return head;
    
    node *h1=head, *t1=head;
    int count=1;

    //Getting the tail node of first 'n' elements
    while(count<n&&t1->next!=NULL){
        t1=t1->next;
        count++;
    }


    node *h2=NULL; // storing node after 'n' elements
    if(t1->next!=NULL)
        h2=t1->next;
    
    t1->next=NULL; // unlinking first 'n' elements from rest of the linked list 

    head=reverse(h1); // reversing the 'n' elements
    
    // Traversing till end of the reversed LL 
    node *temp=head;
	while(temp->next!=NULL)
        temp=temp->next;

	// Calling kReverse recursively on the rest of the linked list
    if(h2!=NULL)
        temp->next=kReverse(h2,n);

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
    head=kReverse(head,n);
    print(head);
    return 0;
}
