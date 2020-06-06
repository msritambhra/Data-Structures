#include<iostream>
using namespace std;


int allIndexes(int input[], int size, int x, int output[]){
    
    if(size==0)
        return 0;
    
    int result = allIndexes(input+1,size-1,x,output);
    
    for(int i =0; i<result; i++)
        output[i]+=1;
	
    if(input[0]==x){
        for(int i = result-1; i>=0; i--)
            output[i+1] = output[i];
        output[0] = 0;
        return result+1;
    }

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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


