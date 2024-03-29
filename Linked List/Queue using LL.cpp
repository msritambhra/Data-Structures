// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }
// } Driver Code Ends


/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{       
    
        struct QueueNode *new_node = new QueueNode(x);
        if(front==NULL){
            front=new_node;
            front->next = NULL;
            rear = front;
            return;
        }
        rear->next = new_node;
        new_node->next = NULL;
        rear = new_node;
        return;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
        if(front==NULL)
            return -1;
        
        int d = front->data;
        front = front->next;
        return d;
        
}
