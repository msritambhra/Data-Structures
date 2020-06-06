#include<iostream>
using namespace std;


int lastIndex(int input[], int size, int x){
    
    if(size==0)
        return -1;

    if(input[size-1]==x)
        return size-1;
    
    int result = lastIndex(input,size-1,x);
    
    if(result==-1)
        return -1;
    else
        return result;
    
    
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


