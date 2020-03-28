
#include <iostream>
#include <climits>
using namespace std;


#include<climits>
int MissingNumber(int arr[], int size){
    
    for(int i = 0; i<size; i++){
        for(int j =i+1; j<size; j++){
            if(i!=j){
                if(arr[i]==arr[j])
                    return arr[i];
            }
            
        }
    }
    
 return INT_MIN;
}


int main() {
	// your code goes here
	int size;
	cin>>size;
	int * input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<MissingNumber(input,size);	
	
	return 0;
}
}