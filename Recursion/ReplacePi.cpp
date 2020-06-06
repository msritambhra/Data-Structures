
// Given a string,compute recursively a new string where all appearances of "pi" have been replaced by "3.14".


#include <iostream>
#include <cstring>
using namespace std;

void replacePiHelper(char input[], int size){
    if(size<=0)
        return;
    
    if(input[0]=='p' && input[1]=='i'){
        for(int i = size+1; i>=0; i--)
            input[i] = input[i-2];
        
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        
        return replacePiHelper(input+4,size-2);
    }
    
    return replacePiHelper(input+1,size-1);
}

void replacePi(char input[]){
    
    int size = strlen(input);
    
    return replacePiHelper(input,size);
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
