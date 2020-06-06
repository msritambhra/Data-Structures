
// Given is the code to print numbers from 1 to n in increasing order recursively.


#include<iostream>
using namespace std;

void print(int n){
    if(n==0)
        return;
    if(n>0){
        
        print(n-1);
        cout<<n<<" ";
    }

}


int main(){
    int n;
    cin >> n;
  
    print(n);
}


