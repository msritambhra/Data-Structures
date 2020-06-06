#include<cstring>
#include <iostream>
using namespace std;

bool checkPalindromehelper(char input[], int start, int end){
    if(start>end)
        return true;
    
    if(input[start]!=input[end])
        return false;
    
    return checkPalindromehelper(input,start+1,end-1);
    
}


bool checkPalindrome(char input[]){
    
    int size = strlen(input);
    
    if(size==0)
        return true;
    
    return checkPalindromehelper(input,0,size-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}