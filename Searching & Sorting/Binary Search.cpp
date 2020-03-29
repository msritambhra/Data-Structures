#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int val){	
	
    int start = 0, end = n-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(arr[mid]==val)
            return mid;
        if(arr[mid]<val)
            start = mid+1;
        else
            end = mid-1;
        mid = (start+end)/2;
    }
    
    return -1;

}



int main() {
	
	int size,val;
	cin>>size;
	int *input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];

	cin>>val;
	cout<<BinarySearch(input,size,val);
	return 0;
}

