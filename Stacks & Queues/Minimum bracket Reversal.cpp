#include <iostream>
using namespace std;

#include <stack>

int countBracketReversals(char input[]){
    
    stack<char> s;
    
    for(int i = 0; input[i]!='\0'; i++){
        
        if(input[i]=='{')
            s.push(input[i]);
        else{
            
            if(!s.empty()){
                if (s.top()=='{')
                    s.pop();
                else{
                    s.push(input[i]);
                }
            }
            else{
                s.push(input[i]);
            }
        }
        
    }
    
    int count = 0;
    
    if(s.size()%2!=0)
        return -1;
    else{
        char c1,c2;
        while(!s.empty()){
            c1 = s.top();
            s.pop();
            c2 = s.top();
            s.pop();
            if(c1==c2)
                count++;
            else
                count+=2;
        }
        
        return count;
    }
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}