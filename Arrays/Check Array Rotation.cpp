#include <iostream>
using namespace std;

int FindSortedArrayRotation(int arr[], int n){
    
    int low = 0, high = n-1;
    
    while(low<high){
        int mid = (high+low)/2;
        
        if(arr[mid]<arr[mid-1] )
            return mid;
        
        if(arr[mid]>arr[mid+1] )
            return mid+1;
        
        if(arr[low]>=arr[mid])
        	high = mid-1;
        else
            low = mid+1;
    }
    
    return -1;
}



int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSortedArrayRotation(input,size);
	
	return 0;

}
