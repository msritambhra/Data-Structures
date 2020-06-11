#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotate(Node* head, int k) {

    if(k==0 || head==NULL || head->next==NULL)
        return head;
    
    Node * head1 = head, *tail = head;
    int count = 0;
    
    while(count<k-1 && tail->next!=NULL){
        tail = tail->next;
        count++;
    }
    
    if(tail->next==NULL)
        return head;
    
    head = tail->next;
    tail->next = NULL;
    tail = head;

    while(tail->next!=NULL)
        tail = tail->next;
    
    tail->next = head1;

    return head;
}


Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main(void) {

    int t, k;

    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k); // rotate linked list anti-clockwise  by k nodes
        printList(head);        // print linked list after rotation
    }
    return (0);
}
