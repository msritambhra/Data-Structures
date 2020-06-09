//Check if a linked list is a palindrome
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


bool check_palindrome(node* head){
    if(head==NULL || head->next == NULL)
        return true;
    node* slow = head;
    node* fast = head;

    while(fast->next!=NULL){
        if(fast->next->next==NULL)
            break;
        slow= slow->next;
        fast = fast->next->next; 
    }
    node* reverse = slow->next;

    node*prev = NULL;
    node*next = NULL;
    node*curr = reverse;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    reverse = prev;
    node*temp = head;
    while(reverse!=NULL){
        if(temp->data == reverse->data){
            temp = temp->next;
            reverse = reverse->next;
        }
        else{
            return false;
        }

    }
    return true;
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
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
