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

node* skipMdeleteN(node  *head, int M, int N){
    if(head==NULL){
        return head;
    }
    if(M==0){
        return NULL;
    }
    
    
    node*temp = head;
    node*slow = head;
    
    int count =0;
    
    while(temp!=NULL){
        
        count = 0;
        
        while(count<M-1 && slow!=NULL){
            slow = slow->next;
            count++;
        }
        
        if(slow!=NULL)
            temp = slow->next;
        else
            return head;
        
        count = 0;
        while(count<N && temp!=NULL){
            
            node*t = temp;
            temp = temp->next;
            delete t;
            count++;
        }
        
        slow->next = temp;
        slow = temp;
        
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

int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
