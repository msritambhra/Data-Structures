#include <string>
#include <iostream>
using namespace std;

void helper(int num, string output,string options[]){
    
    if(num==0){
        cout<<output<<endl;
        return;
    }
    
    int currentNum = num%10;
    
    for(int i = 0; i<options[currentNum].length(); i++){
        helper(num/10,options[currentNum][i] + output, options);
    }
    
    
    
}


void printKeypad(int num){
    string options[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    helper(num,"",options);
    
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
