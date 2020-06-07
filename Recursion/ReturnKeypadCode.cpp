#include <string>
#include <iostream>
using namespace std;

int helper(int num, string output[],string options[]){
    if(num==0){
        output[0]="";
        return 1;
    }
    
    int currentNum = num%10;
    int smallNum = num/10;
    string smallOutput[500];
    int smallLen = helper(smallNum, smallOutput, options);
    string op = options[currentNum];
    
    int k = 0;
    for(int i =0 ;i<op.length(); i++){
		for(int j = 0; j<smallLen;j++){
            output[k] = smallOutput[j] + op[i];
        	k++;
        }
    }
    
    return k;
}
int keypad(int num, string output[]){
    string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n = helper(num,output,options);
    return n;
}



int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

