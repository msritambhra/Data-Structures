#include <iostream>
using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    //delete temp;
}

//To build Min Heap
void buildHeap(int input[],int n, int i){
    
    int child = i;
    int parent = (child-1)/2;
    
    while(parent>=0){
        if(input[child]<input[parent]){
            
            swap(input[child], input[parent]);
            
        }
        else
            break;
        child = parent;
        parent = (child-1)/2;
    }
    
}


//To get the minimum element of the passed input
void removeMin(int input[],int n){
    
    int parentIndex = 0 ;
    int leftChild = 2*parentIndex+1;
    int rightChild = 2*parentIndex+2;
    
    int minIndex; 
    
    while(leftChild<n){
        minIndex=  parentIndex;
        if(input[leftChild]<input[minIndex])
            minIndex = leftChild;
        if(rightChild<n && input[rightChild]<input[minIndex])
            minIndex = rightChild;
        if(minIndex==parentIndex)
            break;
        
        
        swap(input[parentIndex] , input[minIndex]);
        
        
        parentIndex = minIndex;
        leftChild = 2*parentIndex + 1;
        rightChild = 2*parentIndex + 2;
    }
}

void inplaceHeapSort(int input[], int n){
    
    int i;
    for( i = 1;i<n;i++){
        buildHeap(input,n,i);
    }
    
    int size = n;
    while (size>1){
        
        swap(input[0] , input[size-1]); //this gets the minum element to the end of input
        
        size = size-1;
        removeMin(input,size); //Now input with one less size is passed as the last element is in its place.
        
    }  
    

}


int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}
