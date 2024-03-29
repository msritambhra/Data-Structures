#include <iostream>
#include <stack>
using namespace std;


void reverseStack(stack<int> &input, stack<int> &extra) {

    while(!input.empty()){

        int x=input.top();
        extra.push(x);
        input.pop();
    }
    
    input=extra;
}


int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
