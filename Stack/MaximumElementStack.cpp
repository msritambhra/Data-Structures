#include <iostream>
#include <stack>
using namespace std;

class MyStack{
    stack<int> s;
    int maxEle;
    public :
        void getMax();
        void pop();
        void push(int);
};

void MyStack:: push(int x){

    if(s.empty()){
        s.push(x);
        maxEle = x;
        return;
    }

    if(x>maxEle){
        s.push(2*x-maxEle);
        maxEle = x;
        return;
    }

    else{
        s.push(x);
    }
}
void MyStack:: pop(){

    if(s.empty()){
        return;}

    int t = s.top();
    s.pop();

    if(t>=maxEle)
        maxEle = 2*maxEle - t;

    return;
    
}
void MyStack:: getMax(){

    if(s.empty())
            cout<<-1<<endl;
    else
            cout<<maxEle<<endl;
    return;
    
}



int main() {
    int n,c,x; 
    cin>>n;
    MyStack s;
    for(int i = 0; i<n; i++){
        cin>>c;
        if(c==1){
            cin>>x;
            s.push(x);
        }
        else if(c==2)
            s.pop();
        else
            s.getMax();
    }   
    return 0;
}
