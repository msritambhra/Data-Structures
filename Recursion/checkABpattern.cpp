/*

Suppose you have a string, S, made up of only 'a's and 'b's.

Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

*/


#include <iostream>
using namespace std;

bool helperAB(char input[], int start){
    
    if(input[start]=='\0')
        return true;
    
    if(input[start]!='a')
        return false;
    
    if(input[start+1]!='\0' && input[start+2]!='\0'){
        if(input[start+1]=='b' && input[start+2]=='b')
            return helperAB(input,start+3);
    }
    
    return helperAB(input,start+1);
    
    
}

bool checkAB(char input[]) {
	
    return helperAB(input,0);

}


int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}




