
#include <iostream>

using namespace std;

void reverse(int *arr,int start,int end){
    if(start==end)
        return;
    int temp;
    while(start<end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void Rotate(int arr[], int d, int size){
    if(d>=size)
        d = d%size;
    reverse(arr,0,d-1);
    reverse(arr,d,size-1);
    reverse(arr,0,size-1);
       
}


int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}
