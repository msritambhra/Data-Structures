#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */

#include<unordered_map>

int length(Node * head){
    if(head==NULL)
        return 0;
    return 1 + length(head->next);
}

int intersectPoint(Node* head1, Node* head2)
{
    int len1 = length(head1);
    int len2 = length(head2);
    int count = 0;
    if(len1>len2){
        int d = len1 - len2;
        while(count<d){
            head1 = head1->next;
            count++;
        }
            //cout<<head1->data;
    }
    
    else{
        int d = len2 - len1;
        while(count<d){
            head2 = head2->next;
            count++;
        }
            //cout<<head2->data;
    }
    //cout<<head1->data<<" "<<head2->data;
    while(head1!=NULL && head2!=NULL){
        if(head1==head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -1;
}

