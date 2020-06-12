#include <iostream>
#include<stack>
using namespace std;

bool checkRedundantBrackets(char *input){
    
    stack<char> s;
    int count = 0;
    
    for(int i = 0; input[i]!='\0'; i++){
        
        if(input[i]==')'){
            
            while(s.top()!='('){
                s.pop();
                count++;
            }
            
            if(count==0)
                return true;
            count = 0;
            s.pop();      
        }
        else
            s.push(input[i]);
    }
    
    return s.empty();
}


int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
