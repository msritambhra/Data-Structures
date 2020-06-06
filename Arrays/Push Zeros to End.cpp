#include <iostream>
using namespace std;

// arr - input array
// n - size of array

void PushZeroesEnd(int arr[], int n){
    
    int i = 0;
    int k = 0;
    
    while(i<n && k<n){
        
        if(i!=k && arr[i]!=0){
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
        
        if(arr[k]!=0)
            k++;
        
        i++;
        
    }

}



int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	PushZeroesEnd(input,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	
	return 0;

}
